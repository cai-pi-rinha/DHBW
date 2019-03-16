#ifndef HTTP_CLIENT_H
#define HTTP_CLIENT_H

#include "TCP_client.hpp"

class HTTP_Header;  // TODO: correct name?
typedef HTTP_Header t_HTTP_header;

class HTTP_client : public TCP_client
{
    private:

    public:
        HTTP_client(int buffer_size = DEFAULT_BUFLEN);
        HTTP_client(const char* ip, const char* port, int buffer_size = DEFAULT_BUFLEN);
        virtual ~HTTP_client();
        HTTP_client(const HTTP_client& other);

        int start_client(void);
        int send(String* message);
        int receive(void);
        t_HTTP_header get_http_header(void)
        int terminate_connection();
};

#endif // HTTP_CLIENT_H
