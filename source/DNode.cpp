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
    /* fix pointer issues with next and prev element (if there are any) and delete this element */
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
	//sollte doch das dnode remove, nicht die payload löschen?
    if(payload)
    {
        DestroyFuncDNode destroyFunc_ptr = myList->getDestroyFuncPtr();
        if(destroyFunc_ptr)
            (*destroyFunc_ptr)(payload);    /* delete payload */
    }
    payload = NULL;
}

int DNode::insertBefore(void* obj)  /** insert a new element in front of the currently selected element */
{
    /* 1) create DNode-object and configure:
	 *      prev-pointer    = previous of this object;
	 *      next-pointer    = this object;
	 *      payload         = obj
	 * 2) change arguments of this object:
	 *      prev-pointer    = created object
	 */
    //if(this->prev == NULL)  /* quit if there is no DNode object in front of this one */
    //    return -1;
	//macht für mich keinen sinn, es soll ja trotzdem was eingefügt werden
   
    DNode* obj_to_insert    = new DNode(obj, this->prev, this, this->myList);
	if (this->prev != NULL)
		this->prev->next        = obj_to_insert;
	this->prev              = obj_to_insert;
    

    return 0;
}

int DNode::insertAfter(void* obj)  /** insert a new element after the currently selected element */
{
    /* compare with insertBefore() */

    //if(this->next == NULL) /* quit if there is no DNode object after this one */ 
    //    return -1;


		//wat? warum denn das? ich dachte genau dann soll es ja null sein, weil es grad danach keins gibt
   
        DNode* dNode_to_insert    = new DNode(obj, this, this->next, this->myList);
       if(this->next != NULL)
		   this->next->prev        = dNode_to_insert;
        this->next              = dNode_to_insert;
    

    return 0;
}
