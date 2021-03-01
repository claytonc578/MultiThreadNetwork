#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>

#include "server.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
  Server server;
  int new_socket;


  server.initSocket();
  while (1){
    new_socket = server.acceptConnection();
    
  }


  return 0;
}//main
