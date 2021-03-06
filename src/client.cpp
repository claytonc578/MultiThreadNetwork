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
    cout << "Client connected to Server address\n\n";

    return 0;
}//initClient


int Client::writeSocket(string data)
{
    cout << "\nClient sending data..." << endl;
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

    bzero(buffer, sizeof(buffer));
    read(sock, buffer, MAX_BUFFER_SIZE);
    cout << "Client read buffer: " << buffer << endl;
}
