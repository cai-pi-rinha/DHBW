#include <iostream>
#include "source/string.hpp"
#include "source/TCP.hpp"
#include "source/TCP_server.hpp"
#include "source/TCP_client.hpp"

using namespace std;

int main()
{
    cout << "TCP-Test:" << endl << "enter 's' to start server" << endl << "enter 'c' to start client" << endl;
    if(getchar() == 's')
    {
        cout << "starting server..." << endl;
        //TCP_server mein_server("127.0.0.1","55554", 64);
        TCP_server mein_server("192.168.178.118","55554", 64);
        mein_server.dummy_server();
    }
    else
    {
        cout << "starting client..." << endl;
        TCP_client mein_client("192.168.178.118","55554", 64);
        //TCP_client mein_client("216.58.208.46","80", 64); // google.com
        mein_client.dummy_client();
    }





    return 0;
}
