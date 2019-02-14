#ifndef DNODE_H
#define DNODE_H

#include "dlist.hpp"

class Dnode : public Dlist
{
private:
    Dnode* next;
    Dnode* prev;
    void* payload;

public:
    Dnode(void);
    Dnode(void* payload, Dnode* prev, Dnode* next);
    ~Dnode(void);

	Dnode* get_next(void)	{return next;}
	Dnode* get_prev(void)	{return prev;}
	void* get_payload(void)	{return payload;}

	int remove(void);
	int insert_before(void* obj);
	int insert_after(void* obj);
};

#endif
