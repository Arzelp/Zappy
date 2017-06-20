//
// Network.hpp for network in /graphic/include/
//
// Made by Frederic Oddou
// Login   <frederic.oddou@epitech.eu>
//
// Started on  Tue Jun 20 08:49:32 2017 Frederic Oddou
// Last update Tue Jun 20 11:08:44 2017 Frederic Oddou
//

#pragma once

#include <iostream>
#include <queue>
#include <sys/socket.h>
#include <netdb.h>

class NetWork
{
private:
  std::string			_host;
  int				_port;
  int				_socketFd;
  struct sockaddr_in		_socketPort;
  std::queue<std::string>	_queue;
  int				_ipAddr[4];

private:
  bool				InitTcpSocket(void);
  void				InitPortSocket(void);
  bool				GetIp(void);

public:
  NetWork(const std::string &host, int port);
  ~NetWork();
  bool				SendMsg(std::string &str);
  bool	 			ReceiveMsg(void);
  std::string			GetQueue(void);
};
