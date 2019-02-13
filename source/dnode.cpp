#include "dnode.hpp"

// constructor
Dnode::Dnode(void)
{
    // nada
}

Dnode::Dnode(void* payload, Dnode* prev, Dnode* next)
{
    this->payload = payload;
    this->prev = prev;
    this->next = next;
}

// Date member function
