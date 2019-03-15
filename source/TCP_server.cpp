#include <iostream>
#include "TCP_server.hpp"

using namespace std;

TCP_server::TCP_server(int buffer_size)
    : TCP(buffer_size)
{
    print_id();
}
TCP_server::TCP_server(const char* ip, const char* port, int buffer_size)
    : TCP(ip, port, buffer_size)
{
    print_id();
}

TCP_server::~TCP_server()
{
    //dtor
}

TCP_server::TCP_server(const TCP_server& other)
{
    //copy ctor
}

int TCP_server::create_socket_and_bind(void)
{
    int iResult = SOCKET_ERROR;
    // Create a SOCKET for connecting to server
    MasterSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (MasterSocket == INVALID_SOCKET) {
        //printf("socket failed with error: %ld\n", WSAGetLastError());
        cout << "socket failed with error: " << WSAGetLastError() << endl;
        freeaddrinfo(result);
        WSACleanup();
        return 1;
    }

    // Setup the TCP listening socket
    iResult = bind( MasterSocket, result->ai_addr, (int)result->ai_addrlen);
    if (iResult == SOCKET_ERROR) {
        printf("bind failed with error: %d\n", WSAGetLastError());
        freeaddrinfo(result);
        closesocket(MasterSocket);
        WSACleanup();
        return 1;
    }
    return 0;
}

int TCP_server::wait_for_query(void)
{
    freeaddrinfo(result);
    int iResult = 0;
    iResult = listen(MasterSocket, SOMAXCONN);
    if (iResult == SOCKET_ERROR) {
        printf("listen failed with error: %d\n", WSAGetLastError());
        closesocket(MasterSocket);
        WSACleanup();
        return 1;
    }

    // Accept a client socket
    ClientSocket = accept(MasterSocket, NULL, NULL);
    if (ClientSocket == INVALID_SOCKET) {
        printf("accept failed with error: %d\n", WSAGetLastError());
        closesocket(MasterSocket);
        WSACleanup();
        return 1;
    }
    // No longer need server socket
    closesocket(MasterSocket);

    return 0;
}

int TCP_server::process_data()  /** print received data onto the screen */
{
    int http_header_code = 0;
    /*
    // process data in DList; ex. print it:
    cout << "received following data: " << endl;
    Iterator* read_data = receive_buffer_list.MakeIterator();
    do
    {
        cout << (((char*)read_data->Current())+4);
        // if last element in list: check first 4 bytes for length of data within this buffer-packet
    }while(read_data->Next());
    receive_buffer_list.Empty();
    delete(read_data);
    cout << endl;
    */

    /* automatically start the correct processing-function (HTTP/FTP/...) */
    http_header_code = comm_proc->read_and_process_data(&ClientSocket);
    return http_header_code;
}

int TCP_server::start_tcp_server()
{
    int return_value = 0;
    return_value = return_value || init_socket();
    return_value = return_value || create_socket_and_bind();
    return_value = return_value || wait_for_query();
    if(return_value)
        return -1;

    return_value = process_data();  /* returns a HTTP_header code */

    terminate_connection(&ClientSocket);

    return return_value;
}




