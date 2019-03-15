#ifndef COMMPROCESSOR_H
#define COMMPROCESSOR_H

class String;
class TCP;

class comm_processor
{
    private:
        TCP* owner;
    public:
        comm_processor(TCP* owner);
        virtual ~comm_processor();
        comm_processor(const comm_processor& other);

        virtual int read_and_process_data() = 0;
        virtual int send_data() = 0;

};

class http_processor : public comm_processor
{
    private:

    public:
        http_processor(TCP* owner);
        virtual ~http_processor();
        http_processor(const http_processor& other);

        int read_and_process_data();
        int send_data();
};

#endif // COMMPROCESSOR_H
