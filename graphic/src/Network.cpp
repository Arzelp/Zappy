//
// Network.cpp for Network in /graphic/src/
//
// Made by Frederic Oddou
// Login   <frederic.oddou@epitech.eu>
//
// Started on  Tue Jun 20 09:05:24 2017 Frederic Oddou
// Last update Sat Jun 24 22:12:26 2017 arnaud.alies
//

#include <netdb.h>
#include <sys/socket.h>
#include <cstdio>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstdlib>
#include <cstring>
#include <stdexcept>
#include <unistd.h>
#include "Network.hpp"

Network::Network(const std::string &host, int port)
{
  std::cout << "[Network] Opening Network connection." << std::endl;
  this->_host = host;
  this->_port = port;

  if (!this->GetIp() || !this->InitTcpSocket())
    throw std::runtime_error("[Network] Can't get ip and open socket.");
  this->InitPortSocket();
  if (connect(this->_socketFd, (const struct sockaddr *)&this->_socketPort, sizeof(struct sockaddr)) == -1)
    throw std::runtime_error("[Network] Connection failed.");
}

Network::~Network()
{
  if (this->_socketFd)
    {
      close(this->_socketFd);
      std::cout << "[Network] Closing connection from " << this->_host << ":" << this->_port << std::endl;
    }
}

bool			Network::InitTcpSocket(void)
{
  struct protoent	*pe;

  if ((pe = getprotobyname("TCP")) == NULL)
    {
      std::cerr << "[Network] getprotobyname failed." << std::endl;
      return (false);
    }
  if ((this->_socketFd = socket(AF_INET, SOCK_STREAM, pe->p_proto)) == -1)
    {
      std::cerr << "[Network] socket failed." << std::endl;
      return (false);
    }
  return (true);
}

void			Network::InitPortSocket(void)
{
  char			buffer[4096];

  std::memset(buffer, '\0', 4096);
  this->_socketPort.sin_family = AF_INET;
  this->_socketPort.sin_port = htons(this->_port);
  sprintf(buffer, "%d.%d.%d.%d", this->_ipAddr[0], this->_ipAddr[1], this->_ipAddr[2], this->_ipAddr[3]);
  this->_socketPort.sin_addr.s_addr = inet_addr(buffer);
}

bool			Network::GetIp(void)
{
  if (sscanf(this->_host.c_str(), "%d.%d.%d.%d", &this->_ipAddr[0], &this->_ipAddr[1], &this->_ipAddr[2], &this->_ipAddr[3]) != 4)
    {
      if (strcmp(this->_host.c_str(), "localhost"))
	return (false);
      this->_ipAddr[0] = 127;
      this->_ipAddr[1] = 0;
      this->_ipAddr[2] = 0;
      this->_ipAddr[3] = 1;
    }
  return (true);
}

bool				Network::SendMsg(std::string str)
{
  char				buffer[4096];
  int				size;

  if ((size = snprintf(buffer, 4096, "%s\n", str.c_str())) <= 0)
    return (false);
  if (send(this->_socketFd, buffer, size, MSG_NOSIGNAL) == -1)
    {
      std::cerr << "[Network] send failed." << std::endl;
      return (false);
    }
  return (true);
}

void		Network::ReceiveMsg()
{
  std::string	res;
  char		c;
  ssize_t	size;

  while (!this->_endThread)
    {
      while ((size = recv(this->_socketFd, &c, 1, 0)) > 0 && c != '\n')
	{
	  res += c;
	}
      if (size == -1)
	{
	  std::cerr << "[Network] recv failed." << std::endl;
	  this->_endThread = true;
	}
      if (res.length() > 0)
	{
	  this->_mutex.lock();
	  std::cout << "Push" << std::endl;
	  this->_queue.push(res);
	  this->_mutex.unlock();
	  res = "";
	}
    }
  /*
  char				str[4096];
  ssize_t			size;

  while (!this->_endThread)
    {
      std::memset(str, '\0', 4096);
      if ((size = recv(this->_socketFd, str, 4096, 0)) == -1)
	{
	  std::cerr << "[Network] recv failed." << std::endl;
	  this->_endThread = true;
	}
      else if (size > 0 && str[size - 1] == '\n')
	{
	  str[size - 1] = '\0';
	  this->_mutex.lock();
	  std::cout << "Push" << std::endl;
	  this->_queue.push(std::string(str));
	  this->_mutex.unlock();
	}
    }
  */
}

void				Network::ReceiveStop()
{
  _endThread = true;
  _thread.join();
}

void				Network::ReceiveStart()
{
  _endThread = false;
  _thread = std::thread(&Network::ReceiveMsg, this);
}

std::string			Network::GetQueue(void)
{
  std::string			str;

  this->_mutex.lock();
  if ((this->_queue.size()) > 0)
    {
      str = this->_queue.front();
      this->_queue.pop();
      this->_mutex.unlock();
      return (str);
    }
  this->_mutex.unlock();
  return ("");
}

/* MAIN TEST g++ src/Network.cpp -I./include */
/* Main example
int		main()
{
  std::string	str;
  Network	nw("localhost", 10);

  nw.ReceiveStart();
  while (4)
    {
      if ((str = nw.GetQueue()).size())
	{
	  std::cout << str << std::endl;
	  if (!nw.SendMsg("name1"))
	    {
	      nw.ReceiveStop();
	      return (1);
	    }
	  sleep(1);
	}
    }
  return (0);
}
*/
