#ifndef COMMPROCESSOR_H
#define COMMPROCESSOR_H
#include <winsock2.h>

class TCP;
class String;

class comm_processor
{
    private:
        TCP* owner;
    protected:
        TCP* get_owner(void){return owner;}
    public:
        comm_processor(TCP* owner);
        virtual ~comm_processor();
        comm_processor(const comm_processor& other);

        virtual int read_and_process_data(SOCKET* socket) = 0;
        virtual int send_data(SOCKET* DestinationSocket, String* data) = 0;

};

class http_processor : public comm_processor
{
    private:
        int read(SOCKET* socket, String* http_message);
    public:
        http_processor(TCP* owner);
        virtual ~http_processor();
        http_processor(const http_processor& other);

        int read_and_process_data(SOCKET* socket);
        int send_data(SOCKET* DestinationSocket, String* data);
};

#endif // COMMPROCESSOR_H
