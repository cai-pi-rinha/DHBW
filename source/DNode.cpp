#include "DNode.hpp"
#include "DList.hpp"

typedef void (*DestroyFuncDNode)(void*);

// constructor
DNode::DNode(DList* myListPtr)  /** create a new and empty list element */
{
    payload     = NULL;
    prev        = NULL;
    next        = NULL;
    myList      = myListPtr;
}

DNode::DNode(void* payload, DNode* prev, DNode* next, DList* myListPtr) /** create a new list element with (payload, pointer to prev & next element) */
{
    this->payload   = payload;
    this->prev      = prev;
    this->next      = next;
    myList          = myListPtr;
}

DNode::~DNode(void) /** delete the current element EXCLUDING its payload */
{
    if(next)
        next->prev = prev;
    if(prev)
        prev->next = next;
    myList->RefreshNumberOfElements();
}

DNode* DNode::GetNext(void) const
{return next;}
DNode* DNode::GetPrev(void) const
{return prev;}
void* DNode::GetObject(void)
{return payload;}

void DNode::Remove(void)   /** delete the payload */
{
	if (this->next != NULL)
		this->next->prev = prev;
	if (this->prev != NULL)
		this->prev->next = next;
}


int DNode::insertBefore(void* obj)  /** insert a new element in front of the currently selected element */
{
     
    DNode* obj_to_insert    = new DNode(obj, this->prev, this, this->myList);
	if (this->prev != NULL)		//if there is no prev, we are at start of chain
		this->prev->next        = obj_to_insert;
	this->prev              = obj_to_insert;
    

    return 0;
}

int DNode::insertAfter(void* obj)  /** insert a new element after the currently selected element */
{
       DNode* dNode_to_insert    = new DNode(obj, this, this->next, this->myList);
       if(this->next != NULL)
		   this->next->prev        = dNode_to_insert;
        this->next              = dNode_to_insert;
    

    return 0;
}
