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
    Client client2;
    vector<thread> main_threads; //vector of threads in main

    // int *new_socket;


    server.initSocket();
    client1.initClient();
    client2.initClient();


    main_threads.push_back(thread(&Server::acceptConnection, &server));
    main_threads.push_back(thread(&Server::readSocket, &server));
    main_threads.push_back(thread(&Client::writeSocket, &client1, "Hello from client 1"));
    main_threads.push_back(thread(&Client::writeSocket, &client2, "Hello from client 2"));


    // thread serv_accept_thread(&Server::acceptConnection, &server);
    // serv_accept_thread.join();
    // thread client1_write(&Client::writeSocket, &client1, "Hello from client 1");
    // thread server_read(&Server::readSocket, &server);
    // client1_write.join();
    // server_read.join();

    // client1.writeSocket("Hello from client1");
    // server.readSocket();
    // server.writeSocket(new_socket, "Server received message");
    // server.runSocketThread(new_socket);
    // client1.readSocket();
    // client2.writeSocket("Hello from client 2");

    for (unsigned int i = 0; i < main_threads.size(); i++){
        main_threads[i].join();
    }

    return 0;
}//main
