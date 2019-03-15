#ifndef HTTP_SERVER_H
#define HTTP_SERVER_H

#include "TCP_server.hpp"


class HTTP_server : public TCP_server
{
    public:
        HTTP_server(int buffer_size = DEFAULT_BUFLEN);
        HTTP_server(const char* ip, const char* port, int buffer_size = DEFAULT_BUFLEN);
        virtual ~HTTP_server();
        HTTP_server(const HTTP_server& other);

        int start_server(void);

    protected:

    private:
};

#endif // HTTP_SERVER_H
