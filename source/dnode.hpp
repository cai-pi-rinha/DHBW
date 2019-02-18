#ifndef DNODE_H
#define DNODE_H

#include <iostream>

class Dnode
{
private:
    Dnode* next;  /* the pointers are returned in the functions getNext/...; if they wouldn't be 'const' */
    Dnode* prev;  /* the user of the main()-function would be able to change the private attributes of this class */
    void* payload;

public:
    Dnode(void);
    Dnode(void* payload, Dnode* prev, Dnode* next);
    virtual ~Dnode(void);

	Dnode* GetNext(void);
	Dnode* GetPrev(void);
	void* GetObject(void);

	void* Remove(void);
	int insertBefore(void* obj);
	int insertAfter(void* obj);
};

#endif
