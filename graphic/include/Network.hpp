//
// Network.hpp for Network in /graphic/include/
//
// Made by Frederic Oddou
// Login   <frederic.oddou@epitech.eu>
//
// Started on  Tue Jun 20 08:49:32 2017 Frederic Oddou
// Last update Fri Jun 23 11:19:25 2017 Frederic Oddou
//

#pragma once

#include <iostream>
#include <queue>
#include <thread>
#include <mutex>
#include <sys/socket.h>
#include <netdb.h>

class Network
{
private:
  std::string			_host;
  int				_port;
  int				_socketFd;
  struct sockaddr_in		_socketPort;
  std::queue<std::string>	_queue;
  int				_ipAddr[4];
  std::thread			_thread;
  std::mutex			_mutex;
  bool				_endThread;

private:
  bool				InitTcpSocket(void);
  void				InitPortSocket(void);
  bool				GetIp(void);
  void	 			ReceiveMsg();

public:
  Network(const std::string &host, int port);
  ~Network();
  bool				SendMsg(std::string str);
  std::string			GetQueue(void);
  void				ReceiveStop();
  void				ReceiveStart();
};
