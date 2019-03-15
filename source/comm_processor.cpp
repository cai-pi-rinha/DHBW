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
    :comm_processor(owner)
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

int http_processor::read(SOCKET* socket, String* http_message)
{
    int buffer_length = get_owner()->get_buffer_size();
    char* buffer = (char*)malloc(buffer_length);
    int result = 0; /* result contains error code or number of transmitted bytes */

    do
    {
        result = recv(*socket, buffer, buffer_length, 0);
        if(result == 0)
        {
            cout << "connection closing..." << endl;
            return 0;
        }
        else if(result < 0)
        {
            cout << "recv failed with error: " << WSAGetLastError() << endl;
            closesocket(*socket);
            WSACleanup();
            return -1;
        }
        else
        {
            if(result < buffer_length)
                buffer[result] = 0; /* write a binary zero at end of transmission stream */
                *http_message += buffer;
        }
    }while(result == buffer_length);
    free(buffer);

    int position_of_header_termination = 4 + http_message->FindString("\r\n\r\n");
    if( position_of_header_termination != http_message->Length() )
        http_message->Cut(0, position_of_header_termination );

    return 0;
}

int http_processor::read_and_process_data(SOCKET* socket)
{
    /* HTTP_header_object header_obj; */
    String http_header = "";
    String http_body = "";
    String http_response = "<!DOCTYPE html> <html> <body> <h1>My First Heading</h1> <p>My first paragraph.</p> </body> </html>";
    int error = 0;
    int content_length = 0;
    int return_code = 0;    /* return code depending on the received HTTP information */

    /* receive entire HTTP message */
    error = read(socket, &http_header);
    if(error)
        return -1;
    // header_obj.from_string(&http_header);

    /* check the HTTP-Head for a body */
    // content_length = header_obj.get_content_length();
    if(content_length)
    {
        error = read(socket, &http_body);
        if(error)
            return -1;
    }

    /* process received information */
    // return_code = header_obj.get_token_number();
    cout << "received header: " << http_header.GetStr() << endl;
    cout << "received body: " << http_body.GetStr() << endl;

    /* send response */

    send_data(socket, &http_response);

    return return_code;
}

int http_processor::send_data(SOCKET* DestinationSocket, String* data)
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
