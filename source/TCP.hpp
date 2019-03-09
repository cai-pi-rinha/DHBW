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

using namespace std;

class TCP
{
    protected:
        String* source_ip;
        String* source_port;
        String* dest_ip;
        String* dest_port;

        DList receive_buffer_list;
        WSADATA wsaData;
        int iResult;
        SOCKET MasterSocket;    // first Socket created (eg. listen-socket of server or communication socket of client)
        struct addrinfo* result;
        struct addrinfo hints;
        int iSendResult;
        char recvbuf[DEFAULT_BUFLEN];
        int recvbuflen;


        int init_socket(void); /** contains creation of socket() + call of bind() */
        virtual int send_tcp(String* data) = 0;
        virtual int wait_for_receive() = 0;

    public:
        TCP(int buffer_size=DEFAULT_BUFLEN);
        TCP(const char* source_ip, const char* source_port, const char* dest_ip, const char* dest_port, int buffer_size);
        virtual ~TCP();
        TCP(const TCP& other);

    protected:

};

#endif // TCP_H
