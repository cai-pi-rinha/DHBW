#ifndef DLIST_H
#define DLIST_H

#include <iostream>
#include "dnode.hpp"

using namespace std;

class Dlist /* : public ContainerInterface */
{
private:
	Dnode start_of_chain; /* start and end of chain as constant ?? */
	Dnode end_of_chain;
	int number_of_elements;

	Dnode* get_Dnode_element(int index);
	/* get_first() */

public:
    Dlist(void);
	/*	virtual void function() '= 0';
	 *	This is a pure virtual function. Used when there
	 *	is no sensible default implementation for that method.
	 *	This means, that subclasses have to implement this
	 *	function, otherwise they are abstract, meaning you
	 *	cannot create objects of that class.
	 */
	int InsertFirst(void* obj);
	int InsertLast(void* obj);
	int InsertAt(int index, void* obj);
	int DeleteAt(int index);
	void* RemoveAt(int index);
	int getNumberOfElements(void);
	Dnode* GetFirst(void);
	Dnode* GetLast(void);

	void* operator [](int index);
};

#endif
