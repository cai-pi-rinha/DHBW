#ifndef DLIST_H
#define DLIST_H

#include "dnode.hpp"

class Dlist : public Container
{
private:
	Dnode start_of_chain; /* start and end of chain as constant ?? */
	Dnode end_of_chain;
	/* get_first() */

public:
    Dlist(void);
	virtual int remove(int);
	virtual int insert(void* obj);
	virtual int create(void);
	/*	'= 0';
	 *	This is a pure virtual function. Used when there
	 *	is no sensible default implementation for that method.
	 *	This means, that subclasses have to implement this
	 *	function, otherwise they are abstract, meaning you
	 *	cannot create objects of that class.
	 */
	int insertfirst(void* obj);
	int insertlast(void* obj);
	void* operator [](int index);
};

#endif
