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
  Client client;
  int new_socket;
  pid_t pid;

  client.initClient();

  client.sendData("Hello from client");
  client.readSocket();
  return 0;
}//main
