#include "TCP.hpp"

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
    hints.ai_flags = AI_PASSIVE;

    // Resolve the server address and port
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

