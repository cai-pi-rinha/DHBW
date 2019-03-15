#include "HTTP_server.hpp"
#include "comm_processor.hpp"

HTTP_server::HTTP_server(int buffer_size)
    : TCP_server(buffer_size)
{
    comm_proc = new http_processor(this);
}

HTTP_server::HTTP_server(const char* ip, const char* port, int buffer_size)
    : TCP_server(ip, port, buffer_size)
{
    comm_proc = new http_processor(this);
}


HTTP_server::~HTTP_server()
{
    //dtor
}

HTTP_server::HTTP_server(const HTTP_server& other)
{
    //copy ctor
}

int HTTP_server::start_server(void)
{
    int HTTP_header_code = 0;
    do
    {
        HTTP_header_code = start_tcp_server();
        cout << "received header code: " << HTTP_header_code << endl;

    }while(!HTTP_header_code);

    return -1;
}
