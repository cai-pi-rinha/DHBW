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
// Need to link with Ws2_32.lib
#pragma comment (lib, "Ws2_32.lib")

#define DEFAULT_BUFLEN 512
#define DEFAULT_PORT "27015"

class TCP
{
    private:
        struct addrinfo source;
        struct addrinfo dest;
        virtual int init_socket(void) = 0;
        virtual int send_tcp(String* data) = 0;
        virtual String* receive_polling(void) = 0;

    public:
        TCP();
        TCP(String* source_ip, uint16_t source_port, String* dest_ip, uint16_t dest_port);
        virtual ~TCP();
        TCP(const TCP& other);

    protected:

};

#endif // TCP_H
