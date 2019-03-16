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


int HTTP_client::start_client(void) /** init, start & connect TCP client */
{
    return start_tcp_client();
}

int HTTP_client::send(String* message)  /** executes comm_processor::write() */
{

}

int HTTP_client::receive(void)      /** executes comm_processor::read() */
{

}

t_HTTP_header HTTP_client::get_http_header(void)
{

}

int HTTP_client::terminate_connection()
{
    return TCP::terminate_connection(&MasterSocket);
}
