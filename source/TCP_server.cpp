#include <iostream>
#include "TCP_server.hpp"

using namespace std;

TCP_server::TCP_server(int buffer_size)
    : TCP(buffer_size)
{

}
TCP_server::TCP_server(const char* port, int buffer_size)
    : TCP("", port, "", "", buffer_size)
{

}

TCP_server::~TCP_server()
{
    //dtor
}

TCP_server::TCP_server(const TCP_server& other)
{
    //copy ctor
}

int TCP_server::wait_for_query(void)
{
    freeaddrinfo(result);

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

int TCP_server::wait_for_receive()
{
    int result = 0;
    char* buffer;
    do
    {
        buffer  = (char*)malloc(recvbuflen+4); // 4 bytes containing the number of bytes in the buffer + actual buffer itself
        result = recv(ClientSocket, (buffer+4), recvbuflen, 0);
        *(buffer+0) = (result >> 24) & 0xff;
        *(buffer+1) = (result >> 16) & 0xff;
        *(buffer+2) = (result >>  8) & 0xff;
        *(buffer+3) = (result      ) & 0xff;

        if (result > 0) {
            /*
             *  2 options:
             *  A) received less than 'recvbuflen' bytes => transmission completed ~> start processing of data
             *  b) received exactly 'recvbuflen' bytes => transmission probably incomplete ~> continue receiving
             */
            receive_buffer_list.Insert(buffer); // add a new buffer-element to the list
        }
        else if (result == 0)
        {
            printf("Connection closing...\n");
            return 0;
        }
        else  {
            printf("recv failed with error: %d\n", WSAGetLastError());
            closesocket(ClientSocket);
            WSACleanup();
            return -1;
        }
    }while(result == recvbuflen);   // continue receiving until less then max. number of bytes are received



    return 0;
}

int TCP_server::process_data()  /** print received data onto the screen */
{
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

}

int TCP_server::send_tcp(String* data)
{
    int result = SOCKET_ERROR;
    result = send( ClientSocket, data->GetStr(), data->Length(), 0 );
    if (result == SOCKET_ERROR) {
        printf("send failed with error: %d\n", WSAGetLastError());
        closesocket(ClientSocket);
        WSACleanup();
        return 1;
    }
    return 0;
}

int TCP_server::terminate_connection(void)
{
    // shutdown the connection since we're done
    iResult = shutdown(ClientSocket, SD_SEND);
    if (iResult == SOCKET_ERROR) {
        printf("shutdown failed with error: %d\n", WSAGetLastError());
        closesocket(ClientSocket);
        WSACleanup();
        return 1;
    }
    // cleanup
    closesocket(ClientSocket);
    WSACleanup();

    return 0;
}

int TCP_server::start_server(void)
{
    int dummy_counter = 0;
    String welcome_msg("Buenos dias senor(a)!\n");
    do
    {
    init_socket();
    wait_for_query();

        cout << "waiting for something to do..." << endl;
        wait_for_receive();
        process_data();

        dummy_counter = (dummy_counter+1)&0xf;
        if (dummy_counter == 0)
            dummy_counter = 1;
        for(int i=0; i<dummy_counter; i++)
            send_tcp(&welcome_msg);
        terminate_connection();

    }while(1);

    return 0;
}



