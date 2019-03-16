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
    /* create HTTP header and add the message */
    t_HTTP_header new_header;
    // TODO: add the string message to the header

    /* cast communication_processor to a HTTP_processor to replace the http_header by new_header */
    ((http_processor*)comm_proc)->set_http_header(new_header);

    return comm_proc->write(&MasterSocket);
}

int HTTP_client::receive(void)      /** executes comm_processor::read() */
{
    return comm_proc->read(&MasterSocket);
}

t_HTTP_header HTTP_client::get_http_header(void)
{
    return ((http_processor*)comm_proc)->get_http_header();
}

int HTTP_client::terminate_connection()
{
    return TCP::terminate_connection(&MasterSocket);
}
