#ifndef TCP_SERVER_H
#define TCP_SERVER_H

#include "TCP.hpp"
#include "string.hpp"


class TCP_server : public TCP
{
    private:
        SOCKET ClientSocket = INVALID_SOCKET;


        int init_socket_old(void);
        int send_tcp(String* data);
        String* receive_polling(void);

    public:
        TCP_server();
        TCP_server(const char* port);
        virtual ~TCP_server();
        TCP_server(const TCP_server& other);
        int start_server(void);

    protected:
};

#endif // TCP_SERVER_H
