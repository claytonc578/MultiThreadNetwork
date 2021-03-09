#include "server.hpp"

using namespace std;


Server::Server():connect_thread() {}//constructor
Server::~Server()
{
    connect_thread.join();
    cout << "Server connection thread finished\n";
}//destructor

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
    // cout << "Server set socket options completed" << endl;


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
    cout << "Server listening\n\n";

}//initSocket


void Server::acceptConnection()
{
    int addr_len = sizeof(address);

    // cout << "Server accepting connection" << endl;
    while (numThread < MAX_NUM_THREADS){
        /*
        * sockfd
        * addr
        * addrlen
        */
        // cout << "In while loop" << endl;

        connect_fd = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addr_len);
        // cout << "called accept" << endl;

        if (connect_fd < 0){
            perror("server accept failure");
            exit(EXIT_FAILURE);
        }

        cout << "Server accepting connection complete" << endl;

        threads.push_back(thread(&Server::readSocket, this)); //create thread

        // cout << "Called thread readSocket\n";

        mtx.lock();
        numThread++;
        mtx.unlock();
    }

    for (int i = 0; i < MAX_NUM_THREADS; i++){
        threads[i].join();
    }

}//acceptConnection


void Server::readSocket()
{
    char buffer[MAX_BUFFER_SIZE];
    // int read_val;
    mtx.lock();
    cout << "Server numThread: " << numThread << endl;
    mtx.unlock();

    bzero(buffer, sizeof(buffer));
    read(connect_fd, buffer, MAX_BUFFER_SIZE);
    cout << "Server read buffer: " << buffer << endl;
}


int Server::writeSocket(int *new_socket, string data)
{
    cout << "Server sending data..." << endl;

    if (send(*new_socket, data.c_str(), strlen(data.c_str()), 0) < 0){
        cout << "Send failed" << endl;
        return ERROR;
    }

    cout << "Server data send success" << endl;
    return SUCCESS;
}


// void Server::runConnectThread(int *new_socket)
// {
//     while (1){
//         connect_thread = thread(&Server::acceptConnection, this, new_socket);
//
//     }
// }


// void Server::runSocketThread(int *new_socket)
// {
//     thread socket_thread(&Server::readSocket, this, new_socket);
//     thread writeSock_thread(&Server::writeSocket, this, new_socket, "Server received\n");
//     socket_thread.join();
//     writeSock_thread.join();
// }

// void Server::runServer()
// {
//     while (1)
//     {
//         runConnectThread(new_socket);
//     }
// }
