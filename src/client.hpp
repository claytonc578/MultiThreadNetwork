#ifndef _CLIENT_H
#define _CLIENT_H

#include <netinet/in.h>

using namespace std;

#define PORT 4040
#define ERROR -1
#define MAX_BUFFER_SIZE 1024

class Client
{
public:
  Client();
  int initClient();

private:
  int sock;
  const char *address;
  struct sockaddr_in serv_addr;

};

#endif //_CLIENT_H
