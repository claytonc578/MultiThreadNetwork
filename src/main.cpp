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
    Client client1;
    // Client client2;
    int *new_socket;


    server.initSocket();
    client1.initClient();
    // client2.initClient();

    // server.acceptConnection(new_socket);
    server.runConnectThread(new_socket);



    client1.writeSocket("Hello from client");
    // server.readSocket(new_socket);
    // server.writeSocket(new_socket, "Server received message");
    server.runSocketThread(new_socket);
    client1.readSocket();
    return 0;
}//main
