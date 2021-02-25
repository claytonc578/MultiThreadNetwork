#ifndef _SERVER_H
#define _SERVER_H

#include <netinet/in.h>

using namespace std;

#define PORT 4040
#define MAX_NUM_CONNECT 4
#define MAX_BUFFER_SIZE 1024


class Server
{
public:
  Server();
  void initSocket();
  int acceptConnection();
private:
  int server_fd;
  int opt = 1; //option value
  struct sockaddr_in address;

};

#endif //_SERVER_H
