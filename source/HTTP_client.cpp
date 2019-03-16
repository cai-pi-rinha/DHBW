#include "HTTP_client.hpp"
#include "comm_processor.hpp"

HTTP_client::HTTP_client(int buffer_size)
    : TCP_client(buffer_size)
{
    comm_proc = new http_processor(this);
}

HTTP_client::HTTP_client(const char* ip, const char* port, int buffer_size)
    : TCP_client(ip, port, buffer_size)
{
    comm_proc = new http_processor(this);
}

HTTP_client::~HTTP_client()
{
    terminate_connection();
}

HTTP_client::HTTP_client(const HTTP_client& other)
{
    //copy ctor
}
