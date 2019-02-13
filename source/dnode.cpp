#include "dnode.hpp"

// constructor
Dnode::Dnode(void)
{
    payload = NULL;
    prev    = NULL;
    next    = NULL;
}

Dnode::Dnode(void* payload, Dnode* prev, Dnode* next)
{
    this->payload   = payload;
    this->prev      = prev;
    this->next      = next;
}

Dnode::~Dnode(void)
{
    remove();
}

void Dnode::remove(void)
{
    /* fix pointer issues with next and prev element and delete this element */
    Dnode* this_object  = this;
    next->prev          = prev;
    prev->next          = next;
    delete this_object;
}

int Dnode::insert_before(void* obj)
{
    /* 1) create dnode-object and configure:
	 *      prev-pointer    = previous of this object;
	 *      next-pointer    = this object;
	 *      payload         = obj
	 * 2) change arguments of this object:
	 *      prev-pointer    = created object
	 */
    Dnode* obj_to_insert    = new Dnode(obj, this->prev, this);
    this->prev              = obj_to_insert;

    return 0;
}

int Dnode::insert_after(void* obj)
{
    /* compare insert_before() */
    Dnode* obj_to_insert    = new Dnode(obj, this, this->next);
    this->next              = obj_to_insert;

    return 0;
}
