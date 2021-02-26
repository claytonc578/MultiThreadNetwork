#include "server.hpp"

using namespace std;



Server::Server()
{

}//constructor

void Server::initSocket()
{
  /*
  * domain: AF_INET: IPv4 protocol
  * type: SOCK_STREAM: TCP
  * protocol: 0, Internet protocol
  */
  server_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (server_fd < 0){
    perror("Server create socket failed");
    exit(EXIT_FAILURE);
  }//create socket
  cout << "Server created socket" << endl;

  /*
  * sockfd:
  * level: SOL_SOCKET, manipulate options at socket API level
  * optname: SO_REUSEADDR SO_REUSEPORT
  * optval
  * optlen
  */
  if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))){
    perror("server setsockopt");
    exit(EXIT_FAILURE);
  }//attach socket to port 4040
  cout << "Server set socket options completed" << endl;


  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(PORT);

  // char * print_addr = inet_ntoa(address.sin_addr);
  // cout << "Server address: " << print_addr << endl;

  /*
  * sockfd
  * addr:
  * addr_len: length of address
  */
  if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0){
    perror("server bind failure");
    exit(EXIT_FAILURE);
  }
  cout << "Server binded to port" << endl;


  /*
  * sockfd
  * backlog: max num of queue of pending connections
  */
  if (listen(server_fd, MAX_NUM_CONNECT) < 0){
    perror("server listen failure");
    exit(EXIT_FAILURE);
  }
  cout << "Server listening" << endl;

}//initSocket


int Server::acceptConnection()
{
  int new_socket;
  int addr_len = sizeof(address);

  // cout << "Server accepting connection" << endl;

  /*
  * sockfd
  * addr
  * addrlen
  */
  new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addr_len);
  if (new_socket < 0){
    perror("server accept failure");
    exit(EXIT_FAILURE);
  }

  cout << "Server accepting connection complete" << endl;
  return new_socket;
}//acceptConnection


void Server::readSocket(int new_socket)
{
  char buffer[MAX_BUFFER_SIZE];
  int read_val;

  read_val = read(new_socket, buffer, MAX_BUFFER_SIZE);
  cout << "Server read buffer: " << buffer << endl;
}

int Server::writeSocket(int new_socket, string data)
{
  cout << "Server sending data..." << endl;
  // cout << data << endl;

  if (send(new_socket, data.c_str(), strlen(data.c_str()), 0) < 0){
    cout << "Send failed" << endl;
    return ERROR;
  }

  cout << "Server data send success" << endl;
  return SUCCESS;
}



// int main(int argc, char const *argv[])
// {
//   // int new_socket, valread; //socket file descriptor
//
//   // char buffer[MAX_BUFFER_SIZE];
//   // char hello[MAX_BUFFER_SIZE] = "Hello from server";
//
//   // valread = read(new_socket, buffer, MAX_BUFFER_SIZE);
//   // cout << "buffer: " << buffer << endl;
//   // send(new_socket, hello, strlen(hello), 0);
//   // cout << "message sent" << endl;
//   return 0;
// }//main
