#ifndef DNODE_H
#define DNODE_H

#include <iostream>

using namespace std;

class DList;    /* Tell compiler that there will be a class DList at some point of time; important for "DList* myList"; no problem as here only a pointer to DList is required */
class DNode
{
private:
    DNode* next;  /* the pointers are returned in the functions getNext/...; if they wouldn't be 'const' */
    DNode* prev;  /* the user of the main()-function would be able to change the private attributes of this class */
    void* payload;
    DList* myList;

public:
    DNode(DList* myListPtr = NULL);
    DNode(void* payload, DNode* prev, DNode* next, DList* myListPtr = NULL);
    virtual ~DNode();

	DNode* GetNext() const;
	DNode* GetPrev() const;
	void* GetObject();

	void Remove();
	int insertBefore(void* obj);
	int insertAfter(void* obj);
};

#endif
