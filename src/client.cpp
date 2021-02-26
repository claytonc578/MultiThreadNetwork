#include "client.hpp"

using namespace std;



Client::Client()
{
  sock = -1;
  address = SERVER_ADDR;
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
  if (inet_pton(AF_INET, address, &serv_addr.sin_addr) <= 0){
    cout << "Client invalid address/ address not supported" << endl;
    return ERROR;
  }
  cout << "Client convert address completed" << endl;

  //-------------------------Connect to Server--------------------------------------
  if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0){
    cout << "Client connection failed. ERROR" << endl;
    return ERROR;
  }
  cout << "Client connected to Server address" << endl;

  return 0;
}//initClient


int Client::sendData(string data)
{
  cout << "Client sending data..." << endl;
  // cout << data << endl;

  if (send(sock, data.c_str(), strlen(data.c_str()), 0) < 0){
    cout << "Send failed" << endl;
    return ERROR;
  }
  cout << "Client data send success" << endl;
  return SUCCESS;
}

void Client::readSocket()
{
  char buffer[MAX_BUFFER_SIZE];
  int read_val;

  read_val = read(sock, buffer, MAX_BUFFER_SIZE);
  cout << "Client read buffer: " << buffer << endl;
}

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
