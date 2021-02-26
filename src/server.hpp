#ifndef _SERVER_H
#define _SERVER_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <iostream>

using namespace std;

#define PORT 4040
#define MAX_NUM_CONNECT 4
#define MAX_BUFFER_SIZE 1024
#define ERROR -1
#define SUCCESS 0


class Server
{
public:
  Server();
  void initSocket();
  int acceptConnection();
  void readSocket(int new_socket);
  int writeSocket(int new_socket, string data);
private:
  int server_fd;
  int opt = 1; //option value
  struct sockaddr_in address;

};

#endif //_SERVER_H
