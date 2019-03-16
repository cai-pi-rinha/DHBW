#ifndef HTTP_SERVER_H
#define HTTP_SERVER_H

#include "TCP_server.hpp"

class HTTP_Header;  // TODO: correct name?
typedef HTTP_Header t_HTTP_header;

class HTTP_server : public TCP_server
{
    private:

    public:
        HTTP_server(int buffer_size = DEFAULT_BUFLEN);
        HTTP_server(const char* ip, const char* port, int buffer_size = DEFAULT_BUFLEN);
        virtual ~HTTP_server();
        HTTP_server(const HTTP_server& other);

        int start_server(void);
        int get_query(void);
        int process(void);
        int send_response_and_terminate_conn(void);
        int send_alternative_response_and_terminate_conn(String* message);
        int terminate_client_connection(void);
        int terminate_server_connection(void);

        t_HTTP_header get_http_header(void);

    protected:

};

#endif // HTTP_SERVER_H
