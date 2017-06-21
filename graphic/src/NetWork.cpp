//
// NetWork.cpp for Network in /graphic/src/
//
// Made by Frederic Oddou
// Login   <frederic.oddou@epitech.eu>
//
// Started on  Tue Jun 20 09:05:24 2017 Frederic Oddou
// Last update Tue Jun 20 13:24:18 2017 Frederic Oddou
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
#include <fcntl.h>
#include "Network.hpp"

NetWork::NetWork(const std::string &host, int port)
{
  std::cout << "[NetWork] Opening network connection." << std::endl;
  this->_host = host;
  this->_port = port;

  if (!this->GetIp() || !this->InitTcpSocket())
    throw std::runtime_error("[NetWork] Can't get ip and open socket.");
  this->InitPortSocket();
  if (connect(this->_socketFd, (const struct sockaddr *)&this->_socketPort, sizeof(struct sockaddr)) == -1)
    throw std::runtime_error("[NetWork] Connection failed.");
}

NetWork::~NetWork()
{
  if (this->_socketFd)
    {
      close(this->_socketFd);
      std::cout << "[NetWork] Closing connection from " << this->_host << ":" << this->_port << std::endl;
    }
}

bool			NetWork::InitTcpSocket(void)
{
  struct protoent	*pe;

  if ((pe = getprotobyname("TCP")) == NULL)
    {
      std::cerr << "[NetWork] getprotobyname failed." << std::endl;
      return (false);
    }
  if ((this->_socketFd = socket(AF_INET, SOCK_STREAM, pe->p_proto)) == -1)
    {
      std::cerr << "[NetWork] socket failed." << std::endl;
      return (false);
    }
  return (true);
}

void			NetWork::InitPortSocket(void)
{
  char			buffer[4096];

  std::memset(buffer, '\0', 4096);
  this->_socketPort.sin_family = AF_INET;
  this->_socketPort.sin_port = htons(this->_port);
  sprintf(buffer, "%d.%d.%d.%d", this->_ipAddr[0], this->_ipAddr[1], this->_ipAddr[2], this->_ipAddr[3]);
  this->_socketPort.sin_addr.s_addr = inet_addr(buffer);
}

bool			NetWork::GetIp(void)
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

bool				NetWork::SendMsg(std::string &str)
{
  char				buffer[4096];
  int				size;

  if ((size = snprintf(buffer, 4096, "%s\n", str.c_str())) <= 0)
    return (false);
  if (send(this->_socketFd, buffer, size, MSG_NOSIGNAL) == -1)
    {
      std::cerr << "[NetWork] send failed." << std::endl;
      return (false);
    }
  return (true);
}

bool				NetWork::ReceiveMsg(void)
{
  char				str[4096];
  ssize_t			size;

  std::memset(str, '\0', 4096);
  if ((size = recv(this->_socketFd, str, 4096, 0)) == -1)
    {
      std::cerr << "[NetWork] recv failed." << std::endl;
      return (false);
    }
  if (size > 0 && str[size - 1] == '\n')
    {
      str[size - 1] = '\0';
      this->_queue.push(std::string(str));
    }
  return (true);
}

std::string			NetWork::GetQueue(void)
{
  std::string			str;

  if ((this->_queue.size()) > 0)
    {
      str = this->_queue.front();
      this->_queue.pop();
      std::cout << "Coucou" << std::endl;
      return (str);
    }
  return (NULL);
}

/* MAIN TEST g++ src/NetWork.cpp -I./include
int		main()
{
  std::string	str;
  NetWork	nw("localhost", 10);

  nw.ReceiveMsg(); // Have to thread in order to un block.
  while ((str = nw.GetQueue()).size())
    std::cout << str << std::endl;
  return (0);
}
*/
