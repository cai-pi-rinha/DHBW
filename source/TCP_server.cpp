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

int TCP_server::start_server(void)
{
    int dummy_counter = 0;
    String welcome_msg("Buenos dias senor(a)!\n");
    do
    {
        init_socket();
        wait_for_query();

        cout << "waiting for something to do..." << endl;
        wait_for_receive(&ClientSocket);
        process_data();

        dummy_counter = (dummy_counter+1)&0xf;
        if (dummy_counter == 0)
            dummy_counter = 1;
        for(int i=0; i<dummy_counter; i++)
            send_tcp(&welcome_msg, &ClientSocket);
        terminate_connection(&ClientSocket);

    }while(1);

    return 0;
}



