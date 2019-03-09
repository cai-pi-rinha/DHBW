#include "TCP.hpp"

/*
 *      https://docs.microsoft.com/en-us/windows/desktop/winsock/complete-client-code
 */

void DestroyReceiveBuffer(void* pv)
{ free(pv); }   // OS keeps track of the allocated memory at this position

TCP::TCP(int buffer_size)
{
    this->source_ip     = new String("127.0.0.1");
    this->source_port   = new String(DEFAULT_PORT);
    this->dest_ip       = new String("127.0.0.1");
    this->dest_port     = new String(DEFAULT_PORT);
    cout << "source port filled in TCP std-constructor with: " << source_port->GetStr() << endl;
    recvbuflen = buffer_size;
    receive_buffer_list = *(new DList(&DestroyReceiveBuffer));
}

TCP::TCP(const char* source_ip, const char* source_port, const char* dest_ip, const char* dest_port, int buffer_size)
    : TCP(buffer_size) // call the main TCP constructor and subsequently make a few changes
{
    this->source_ip     = new String(source_ip);
    this->source_port   = new String(source_port);
    this->dest_ip       = new String(dest_ip);
    this->dest_port     = new String(dest_port);
    cout << "Port: " << this->source_port->GetStr() << " buffer: " << recvbuflen << endl;

}

TCP::~TCP()
{
    delete(source_ip);
    delete(source_port);
    delete(dest_ip);
    delete(dest_port);
}

TCP::TCP(const TCP& other)
{
    //copy ctor
}

int TCP::init_socket(void)
{
    cout << "init socket" << endl;

    MasterSocket = INVALID_SOCKET;
    result = NULL;

    // Initialize Winsock
    iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
    if (iResult != 0) {
        printf("WSAStartup failed with error: %d\n", iResult);
        return 1;
    }

    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    hints.ai_flags = AI_PASSIVE;    // TODO: steht beim client nicht dabei

    // Resolve the server address and port
    // TODO: statt NULL steht beim client hier argv[1]
    iResult = getaddrinfo(NULL, source_port->GetStr(), &hints, &result);
    if ( iResult != 0 ) {
        printf("getaddrinfo failed with error: %d\n", iResult);
        WSACleanup();
        return 1;
    }

    // Create a SOCKET for connecting to server
    MasterSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (MasterSocket == INVALID_SOCKET) {
        //printf("socket failed with error: %ld\n", WSAGetLastError());
        cout << "socket failed with error: " << WSAGetLastError() << endl;
        freeaddrinfo(result);
        WSACleanup();
        return 1;
    }

    // Setup the TCP listening socket
    iResult = bind( MasterSocket, result->ai_addr, (int)result->ai_addrlen);
    if (iResult == SOCKET_ERROR) {
        printf("bind failed with error: %d\n", WSAGetLastError());
        freeaddrinfo(result);
        closesocket(MasterSocket);
        WSACleanup();
        return 1;
    }

    return 0;
}

int TCP::wait_for_receive(SOCKET* ClientSocket)
{
    int result = 0;
    char* buffer;
    do
    {
        buffer  = (char*)malloc(recvbuflen+4); // 4 bytes containing the number of bytes in the buffer + actual buffer itself
        result = recv(*ClientSocket, (buffer+4), recvbuflen, 0);
        *(buffer+0) = (result >> 24) & 0xff;
        *(buffer+1) = (result >> 16) & 0xff;
        *(buffer+2) = (result >>  8) & 0xff;
        *(buffer+3) = (result      ) & 0xff;

        if (result > 0) {
            /*
             *  2 options:
             *  A) received less than 'recvbuflen' bytes => transmission completed ~> start processing of data
             *  b) received exactly 'recvbuflen' bytes => transmission probably incomplete ~> continue receiving
             */
            receive_buffer_list.Insert(buffer); // add a new buffer-element to the list
        }
        else if (result == 0)
        {
            printf("Connection closing...\n");
            return 0;
        }
        else  {
            printf("recv failed with error: %d\n", WSAGetLastError());
            closesocket(*ClientSocket);
            WSACleanup();
            return -1;
        }
    }while(result == recvbuflen);   // continue receiving until less then max. number of bytes are received

    return 0;
}

int TCP::send_tcp(String* data, SOCKET* DestinationSocket)
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

int TCP::terminate_connection(SOCKET* destinationSocket)
{
    // shutdown the connection since we're done
    int result = SOCKET_ERROR;
    result = shutdown(*destinationSocket, SD_SEND);
    if (result == SOCKET_ERROR) {
        printf("shutdown failed with error: %d\n", WSAGetLastError());
        closesocket(*destinationSocket);
        WSACleanup();
        return 1;
    }
    // cleanup
    closesocket(*destinationSocket);
    WSACleanup();

    return 0;
}
