#ifndef DLIST_H
#define DLIST_H

#include "dnode.hpp"

class Dlist : public Container
{
private:
	Dnode start_of_chain; /* start and end of chain as constant ?? */
	Dnode end_of_chain;
	int number_of_elements;

	Dnode* get_Dnode_element(int index);
	/* get_first() */
	/* FUNKTIONSNAMEN AN UML ANPASSEN !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */

public:
    Dlist(void);
	virtual int Remove(int);
	virtual int create(void);
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

	void* operator [](int index);
};

#endif
