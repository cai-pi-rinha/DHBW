#include "comm_processor.hpp"
#include "TCP.hpp"

comm_processor::comm_processor(TCP* owner)
    : owner(owner)
{
    //ctor
}

comm_processor::~comm_processor()
{
    //dtor
}

comm_processor::comm_processor(const comm_processor& other)
{
    //copy ctor
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////

http_processor::http_processor(TCP* owner)
    :comm_processor(owner),
     received_header(new t_HTTP_header), received_body(new t_HTTP_body),
     sent_header(new t_HTTP_header), sent_body(new t_HTTP_body)
{
    //ctor
}

http_processor::~http_processor()
{
    //dtor
}

http_processor::http_processor(const http_processor& other) /* copy constructor with inheritance */
    :comm_processor(other)
{
    //copy ctor
}

String http_processor::read_string(SOCKET* socket)
{
    String http_message = "";
    int buffer_length = get_owner()->get_buffer_size();
    char* buffer = (char*)malloc(buffer_length);
    int result = 0; /* result contains error code or number of transmitted bytes */

    do
    {
        result = recv(*socket, buffer, buffer_length, 0);
        if(result == 0)
        {
            cout << "connection closing..." << endl;
            return http_message;
        }
        else if(result < 0)
        {
            cout << "recv failed with error: " << WSAGetLastError() << endl;
            closesocket(*socket);
            WSACleanup();
            return http_message;
        }
        else
        {
            if(result < buffer_length)
                buffer[result] = 0; /* write a binary zero at end of transmission stream */
                http_message += buffer;
        }
    }while(result == buffer_length);
    free(buffer);

    int position_of_header_termination = 4 + http_message.FindString("\r\n\r\n");
    if( position_of_header_termination != http_message.Length() )
        http_message.Cut(0, position_of_header_termination );

    return http_message;
}

int http_processor::write_string(SOCKET* DestinationSocket, String* data)
{
    int result = SOCKET_ERROR;
    result = send( *DestinationSocket, data->GetStr(), data->Length(), 0 );
    if (result == SOCKET_ERROR) {
        printf("send failed with error: %d\n", WSAGetLastError());
        closesocket(*DestinationSocket);
        WSACleanup();
        return 1;
    }
    return 0;
}

int http_processor::read(SOCKET* socket)
{
    String http_header = "";
    String http_body = "";
    int content_length = 0;

    /* receive HTTP header */
    http_header = read_string(socket);
    if(http_header.Length() == 0)
        return -1;
    received_header->from_String(&http_header);  // TODO: use of from_String() correct?

    /* check the HTTP-Head for a body */
    // content_length = received_header.get_content_length();
    if(content_length)
    {
        http_body = read_string(socket);
        if(http_body.Length() == 0)
            return -1;
        received_body->from_String(&http_body);  // TODO: use of from_String() correct?
    }

    return 0;
}

int http_processor::process()
{
    /* take information from "received_header" and transfer it into the "sent_header" */

    sent_header = received_header;  // TODO: process information in some way
    sent_body = received_body;

    return 0;
}

int http_processor::write(SOCKET* DestinationSocket, String* data)
{
    if(data)    // TODO: add function to put data-string into header before sending
        {}//sent_header.add_string(data);
    int error = 0;
    //error = write_string(DestinationSocket, &sent_header.to_String());  // TODO: implement HTTP functions with to_String()
    //error += write_string(DestinationSocket, &sent_body.to_String());

    if(error)
        return -1;
    return 0;
}

t_HTTP_header http_processor::get_http_header(void)
{
    return *received_header;
}
