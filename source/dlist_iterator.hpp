#ifndef DNODE_ITERATOR_H
#define DNODE_ITERATOR_H

class Dlist_Iterator : public Dnode : public Iterator_Impl
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
