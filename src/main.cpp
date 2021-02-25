#include <stdio.h>
#include <stdlib.h>

#include "server.hpp"
#include "client.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
  Server server;
  Client client;

  server.initSocket();
  client.initClient();
  server.acceptConnection();
  return 0;
}//main
