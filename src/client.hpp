#ifndef _CLIENT_H
#define _CLIENT_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <iostream>
#include <string>

using namespace std;

#define PORT 4040
#define ERROR -1
#define SUCCESS 0
#define MAX_BUFFER_SIZE 1024
#define SERVER_ADDR "0.0.0.0"

class Client
{
public:
Client();
int initClient();
int writeSocket(string data);
void readSocket();

private:
int sock;
const char *address;
struct sockaddr_in serv_addr;

};

#endif //_CLIENT_H
