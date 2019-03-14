#ifndef TCP_CLIENT_H
#define TCP_CLIENT_H

#include <TCP.hpp>


class TCP_client : public TCP
{
    private:
        int connect_socket(void);
        void process_data(void);

    public:
        TCP_client(int buffer_size=DEFAULT_BUFLEN);
        TCP_client(const char* ip, const char* port, int buffer_size=DEFAULT_BUFLEN);
        virtual ~TCP_client();
        TCP_client(const TCP_client& other);

        int dummy_client(void);

};

#endif // TCP_CLIENT_H
