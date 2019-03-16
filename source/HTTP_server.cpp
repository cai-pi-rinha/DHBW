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
    terminate_client_connection();
    terminate_server_connection();
}

HTTP_server::HTTP_server(const HTTP_server& other)
{
    //copy ctor
}

int HTTP_server::start_server(void) /** init & start TCP server; waits for query */
{
    return start_tcp_server();
}

int HTTP_server::get_query(void)    /** executes comm_processor::read() */
{
    return comm_proc->read(&ClientSocket);
}

int HTTP_server::process(void)      /** executes comm_processor::proccess() */
{
    return comm_proc->process();
}

int HTTP_server::send_response_and_terminate_conn(void)/** executes comm_processor::write() */
{
    int error = 0;
    error = comm_proc->write(&ClientSocket);
    terminate_client_connection();

    return error;
}

int HTTP_server::send_alternative_response_and_terminate_conn(String* message) /** executes comm_processor::write() with a reply message different to the one processed */
{
    int error = 0;
    error = comm_proc->write(&ClientSocket, message);
    terminate_client_connection();

    return error;
}

t_HTTP_header HTTP_server::get_http_header(void)
{
    /* 1) cast generic communication_processor into an HTTP processor  (as this is the HTTP_server class)
     * 2) get the received HTTP header
     */
    return ((http_processor*)comm_proc)->get_http_header();
}

int HTTP_server::terminate_client_connection(void)
{
    return terminate_connection(&ClientSocket);
}

int HTTP_server::terminate_server_connection(void)
{
    return terminate_connection(&MasterSocket);
}
