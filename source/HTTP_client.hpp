#ifndef HTTP_CLIENT_H
#define HTTP_CLIENT_H

#include <TCP_client.hpp>


class HTTP_client : public TCP_client
{
    public:
        HTTP_client();
        virtual ~HTTP_client();
        HTTP_client(const HTTP_client& other);

    protected:

    private:
};

#endif // HTTP_CLIENT_H
