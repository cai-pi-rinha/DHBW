#ifndef TCP_H
#define TCP_H

#undef UNICODE

#define _WIN32_WINNT 0x501
#define WIN32_LEAN_AND_MEAN

#include <iostream>
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include "string.hpp"
#include "DList.hpp"
// Need to link with Ws2_32.lib
#pragma comment (lib, "Ws2_32.lib")

#define DEFAULT_BUFLEN 512
#define DEFAULT_PORT "27015"
#define DEFAULT_IP "127.0.0.1"

using namespace std;

class TCP
{
    protected:
        String* master_ip;
        String* master_port;

        DList receive_buffer_list;
        WSADATA wsaData;
        SOCKET MasterSocket;    // first Socket created (eg. listen-socket of server or communication socket of client)
        struct addrinfo* result;
        struct addrinfo hints;
        int iSendResult;
        char recvbuf[DEFAULT_BUFLEN];
        int recvbuflen;

        /* impossible to create a TCP-object */
        TCP(int buffer_size=DEFAULT_BUFLEN);
        TCP(const char* ip, const char* port, int buffer_size);

        int init_socket(void); /** contains creation of socket() + call of bind() */
        int wait_for_receive(SOCKET* ClientSocket);
        int send_tcp(String* data, SOCKET* DestinationSocket);
        int terminate_connection(SOCKET* destinationSocket);

    public:
        virtual ~TCP();
        TCP(const TCP& other);
        void print_id(void);


    protected:

};

#endif // TCP_H
