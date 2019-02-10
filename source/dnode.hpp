#ifndef DNODE_H
#define DNODE_H

class Dnode : public Dlist
{
private:
    Dnode* next;
    Dnode* prev;
    void* payload;

public:
    Dnode(void);
	
	Dnode* get_next(void)	{return next};
	Dnode* get_prev(void)	{return prev};
	void* get_payload(void)	{return payload};
};

#endif
