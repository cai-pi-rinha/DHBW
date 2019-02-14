#include "dnode.hpp"

// constructor
Dnode::Dnode(void)
{
    payload = NULL;
    prev    = NULL;
    next    = NULL;
}

Dnode::Dnode(void* payload, Dnode* prev, Dnode* next) /** create a new list element with (payload, pointer to prev & next element) */
{
    this->payload   = payload;
    this->prev      = prev;
    this->next      = next;
}

Dnode::~Dnode(void) /** delete the current element INCLUDING its payload */
{
    /* invoke the destructor of payload; might cause troubles, if the payload-element has no destructor */
    delete this.payload;
    /* fix pointer issues with next and prev element and delete this element */
    Dnode* this_object  = this;
    next->prev          = prev;
    prev->next          = next;
    delete this_object;
}

int Dnode::remove(void)   /** remove the payload of this element */
{
    /* erstes oder letztes Element in der Liste?? */


    return 0;
}

int Dnode::insert_before(void* obj)  /** insert a new element in front of the currently selected element */
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

int Dnode::insert_after(void* obj)  /** insert a new element after the currently selected element */
{
    /* compare with insert_before() */

    if(this->next == NULL) /* quit if there is no Dnode object after this one */
        return -1;
    else
    {
        Dnode* obj_to_insert    = new Dnode(obj, this, this->next);
        this->next              = obj_to_insert;
    }

    return 0;
}
