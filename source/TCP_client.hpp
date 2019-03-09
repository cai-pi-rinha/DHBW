#ifndef TCP_CLIENT_H
#define TCP_CLIENT_H

#include <TCP.hpp>


class TCP_client : public TCP
{
    private:

    public:
        TCP_client(int buffer_size=DEFAULT_BUFLEN);
        TCP_client(const char* source_ip, const char* source_port, const char* dest_ip, const char* dest_port, int buffer_size=DEFAULT_BUFLEN);
        virtual ~TCP_client();
        TCP_client(const TCP_client& other);

        int dummy_client(void);

};

#endif // TCP_CLIENT_H
