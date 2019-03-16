#ifndef TCP_SERVER_H
#define TCP_SERVER_H

#include "TCP.hpp"
#include "string.hpp"


class TCP_server : public TCP
{
    private:
        int create_socket_and_bind(void);
        int wait_for_query(void);

    protected:
        SOCKET ClientSocket = INVALID_SOCKET;
        int start_tcp_server(void);
        TCP_server(int buffer_size = DEFAULT_BUFLEN);
        TCP_server(const char* ip, const char* port, int buffer_size = DEFAULT_BUFLEN);

    public:
        virtual ~TCP_server();
        TCP_server(const TCP_server& other);

    protected:
};

#endif // TCP_SERVER_H
