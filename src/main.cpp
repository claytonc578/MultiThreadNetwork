#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>

#include "server.hpp"
#include "client.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
  Server server;
  Client client;
  int new_socket;
  pid_t pid;


  server.initSocket();
  client.initClient();
  new_socket = server.acceptConnection();

  // pid = fork();
  // if (pid < 0){
  //   perror("ERROR: fork")
  // }
  // if (pid == 0){
  //   close(server.server_fd);
  //   server.readSocket(new_socket);
  //   exit(SUCCESS);
  // }
  // else{
  //   close(new_socket);
  // }

  client.sendData("Hello from client");
  server.readSocket(new_socket);
  server.writeSocket(new_socket, "Server received message");
  client.readSocket();
  return 0;
}//main
