#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <iostream>

#include "client.hpp"

using namespace std;


Client::Client()
{
  sock = -1;
  address = "";
}//constructor


int Client::initClient()
{
  //-------------------------Create Socket--------------------------------------
  sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0){
    cout << "Client socket create ERROR" << endl;
    return ERROR;
  }
  cout << "Client socket created" << endl;

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(PORT);

  //-------------------------Convert Address--------------------------------------
  cout << "Client converting address" << endl;
  if (inet_pton(AF_INET, address, &serv_addr.sin_addr) <= 0){
    cout << "Client invalid address/ address not supported" << endl;
    return ERROR;
  }

  //-------------------------Connect to Server--------------------------------------
  if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0){
    cout << "Client connection failed. ERROR" << endl;
    return ERROR;
  }
  cout << "Client connected to address" << endl;

  return 0;
}//initClient

// int main(int argc, char const *argv[])
// {
//   // int valread;
//   // char buffer[MAX_BUFFER_SIZE];
//   // char hello[MAX_BUFFER_SIZE] = "Hello from client";
//
//
//   // send(sock, hello, strlen(hello), 0);
//   // cout << "Client hello message sent" << endl;
//   // valread = read(sock, buffer, MAX_BUFFER_SIZE);
//   // cout << "buffer: " << buffer << endl;
//   return 0;
//
// }//main
