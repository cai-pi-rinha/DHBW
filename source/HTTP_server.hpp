#ifndef HTTP_SERVER_H
#define HTTP_SERVER_H

#include <TCP_server.hpp>


class HTTP_server : public TCP_server
{
    public:
        HTTP_server();
        virtual ~HTTP_server();
        HTTP_server(const HTTP_server& other);

    protected:

    private:
};

#endif // HTTP_SERVER_H
