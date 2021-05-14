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
#include <string>
#include <iostream>
#include <thread>
#include <mutex>
#include <vector>


using namespace std;

#define PORT 4040
#define MAX_NUM_CONNECT 4
#define MAX_BUFFER_SIZE 1024
#define ERROR -1
#define SUCCESS 0
#define MAX_NUM_THREADS 2


class Server
{
public:
Server();
~Server();
void initSocket();
void acceptConnection();
void readSocket();
int writeSocket(int *new_socket, string data);
// void runConnectThread(int *new_socket);
// void runSocketThread(int *new_socket);

private:
int server_fd; //server file descriptor
int opt = 1; //option value
struct sockaddr_in address; //server socket address
thread connect_thread; //thread to handle connections
int numThread = 0; //number of current threads
vector<thread> threads; //vector of threads
int connect_fd;
mutex mtx;

};

#endif //_SERVER_H
