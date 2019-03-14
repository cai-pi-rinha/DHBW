#include "TCP_client.hpp"

TCP_client::TCP_client(int buffer_size)
    : TCP(buffer_size)
{
    print_id();
}

TCP_client::TCP_client(const char* ip, const char* port, int buffer_size)
    : TCP(ip, port, buffer_size)
{
    print_id();
}

TCP_client::~TCP_client()
{
    //dtor
}

TCP_client::TCP_client(const TCP_client& other)
{
    //copy ctor
}

int TCP_client::dummy_client(void)
{
    int iResult = 0;
    String dummy_message("how are you\r\n");
    init_socket();
    iResult = connect_socket();
    while(!iResult)
    {
        cout << "press any key to continue ..." << endl;
        std::cin.ignore();
        iResult = send_tcp(&dummy_message, &MasterSocket);
        iResult = iResult || wait_for_receive(&MasterSocket);
        process_data();
    }


    terminate_connection(&MasterSocket);


    return 0;
}

int TCP_client::connect_socket(void)
{
    struct addrinfo *ptr = NULL;
    int iResult = 0;
    // Attempt to connect to an address until one succeeds
    for(ptr=result; ptr != NULL ;ptr=ptr->ai_next) {

        // Create a SOCKET for connecting to server
        MasterSocket = socket(ptr->ai_family, ptr->ai_socktype,
            ptr->ai_protocol);
        if (MasterSocket == INVALID_SOCKET) {
            cout << "socket failed with error: " << WSAGetLastError() << endl;
            WSACleanup();
            return 1;
        }

        // Connect to server.
        iResult = connect( MasterSocket, ptr->ai_addr, (int)ptr->ai_addrlen);
        if (iResult == SOCKET_ERROR) {
            closesocket(MasterSocket);
            MasterSocket = INVALID_SOCKET;
            continue;
        }
        break;
    }
    freeaddrinfo(result);

    if (MasterSocket == INVALID_SOCKET) {
        printf("Unable to connect to server!\n");
        WSACleanup();
        return 1;
    }
    return 0;
}

void TCP_client::process_data(void)
{
    // process data in DList; ex. print it:
    cout << "received following data: " << endl;
    Iterator* read_data = receive_buffer_list.MakeIterator();
    do
    {
        cout << (((char*)read_data->Current())+4);
        // if last element in list: check first 4 bytes for length of data within this buffer-packet
    }while(read_data->Next());
    receive_buffer_list.Empty();
    delete(read_data);
    cout << endl;
}
