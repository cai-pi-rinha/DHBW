#include "dnode.hpp"

// constructor
Dnode::Dnode(void)  /** create a new and empty list element */
{
    payload = NULL;
    //prev    = (Dnode*)NULL;
    //next    = NULL;
}

Dnode::Dnode(void* payload, Dnode* prev, Dnode* next) /** create a new list element with (payload, pointer to prev & next element) */
{
    this->payload   = payload;
    this->prev      = prev;
    this->next      = next;
}

Dnode::~Dnode(void) /** delete the current element INCLUDING its payload */
{
    /* remove payload */
    this->Remove();
    /* fix pointer issues with next and prev element (if there are any) and delete this element */
    if(next)
        next->prev = prev;
    if(prev)
        prev->next = next;
}

Dnode* Dnode::GetNext(void)
{return next;}
Dnode* Dnode::GetPrev(void)
{return prev;}
void* Dnode::GetObject(void)
{return payload;}

void* Dnode::Remove(void)   /** remove the link between this element and the actual payload */
{
    /* remove the link between Dnode and the actual element; return the elements address to the user to invoke a delete command */
    void* temp = this->payload;
    this->payload = NULL;

    return this->payload;
}

int Dnode::insertBefore(void* obj)  /** insert a new element in front of the currently selected element */
{
    /* 1) create dnode-object and configure:
	 *      prev-pointer    = previous of this object;
	 *      next-pointer    = this object;
	 *      payload         = obj
	 * 2) change arguments of this object:
	 *      prev-pointer    = created object
	 */
    if(this->prev == NULL)  /* quit if there is no Dnode object in front of this one */
        return -1;
    else
    {
        Dnode* obj_to_insert    = new Dnode(obj, this->prev, this);
        this->prev              = obj_to_insert;
    }

    return 0;
}

int Dnode::insertAfter(void* obj)  /** insert a new element after the currently selected element */
{
    /* compare with insertBefore() */

    if(this->next == NULL) /* quit if there is no Dnode object after this one */
        return -1;
    else
    {
        Dnode* obj_to_insert    = new Dnode(obj, this, this->next);
        this->next              = obj_to_insert;
    }

    return 0;
}
