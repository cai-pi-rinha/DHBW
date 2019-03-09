#include <iostream>
#include "TCP_server.hpp"

using namespace std;

TCP_server::TCP_server()
{

}
TCP_server::TCP_server(const char* port)
    : TCP("", port, "", "")
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
    char buffer[recvbuflen+4] = {0};
    // create a string of unknown length and add buffer
    do
    {
        result = recv(ClientSocket, &buffer[4], recvbuflen, 0);
        buffer[0] = (result >> 24) & 0xff;
        buffer[1] = (result >> 16) & 0xff;
        buffer[2] = (result >>  8) & 0xff;
        buffer[3] = (result      ) & 0xff;

        if (result > 0) {
            printf("Bytes received: %d\n", result);
            /*
             *  2 options:
             *  A) received less than 'recvbuflen' bytes => transmission completed ~> start processing of data
             *  b) received exactly 'recvbuflen' bytes => transmission probably incomplete ~> continue receiving
             */

            cout << "-> " << &buffer[4] << endl;
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

int TCP_server::send_tcp(String* data)
{
    cout << "send_tcp()" << endl;
    // Receive until the peer shuts down the connection
    //do {
        // Echo the buffer back to the sender
//            iSendResult = send( ClientSocket, recvbuf, iResult, 0 );
//            if (iSendResult == SOCKET_ERROR) {
//                printf("send failed with error: %d\n", WSAGetLastError());
//                closesocket(ClientSocket);
//                WSACleanup();
//                return 1;
//            }
//            printf("Bytes sent: %d\n", iSendResult);

    //} while (iResult > 0);
    return 0;
}

int TCP_server::init_socket_old(void)
{
    // Receive until the peer shuts down the connection
    do {

        iResult = recv(ClientSocket, recvbuf, recvbuflen, 0);
        if (iResult > 0) {
            printf("Bytes received: %d\n", iResult);

        // Echo the buffer back to the sender
            iSendResult = send( ClientSocket, recvbuf, iResult, 0 );
            if (iSendResult == SOCKET_ERROR) {
                printf("send failed with error: %d\n", WSAGetLastError());
                closesocket(ClientSocket);
                WSACleanup();
                return 1;
            }
            printf("Bytes sent: %d\n", iSendResult);
        }
        else if (iResult == 0)
            printf("Connection closing...\n");
        else  {
            printf("recv failed with error: %d\n", WSAGetLastError());
            closesocket(ClientSocket);
            WSACleanup();
            return 1;
        }

    } while (iResult > 0);

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
    init_socket();
    wait_for_query();
    cout << "wait_for_receive()" << endl;
    wait_for_receive();

    //init_socket_old();
    return 0;
}



