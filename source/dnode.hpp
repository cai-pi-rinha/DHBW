#ifndef DNODE_H
#define DNODE_H

#include <iostream>

using namespace std;

class Dlist;    /* Tell compiler that there will be a class Dlist at some point of time; important for "Dlist* myList"; no problem as here only a pointer to Dlist is required */
class Dnode
{
private:
    Dnode* next;  /* the pointers are returned in the functions getNext/...; if they wouldn't be 'const' */
    Dnode* prev;  /* the user of the main()-function would be able to change the private attributes of this class */
    void* payload;
    Dlist* myList;

public:
    Dnode(Dlist* myListPtr = NULL);
    Dnode(void* payload, Dnode* prev, Dnode* next, Dlist* myListPtr = NULL);
    virtual ~Dnode(void);

	Dnode* GetNext(void);
	Dnode* GetPrev(void);
	void* GetObject(void);

	void Remove(void);
	int insertBefore(void* obj);
	int insertAfter(void* obj);
};

#endif
