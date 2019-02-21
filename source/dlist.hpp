#ifndef DLIST_H
#define DLIST_H

#include <iostream>
#include "dnode.hpp"

using namespace std;

typedef void (*DestroyFunc)(void*); /* used in DeleteAt() */

class Dlist /* : public ContainerInterface */
{
private:
	Dnode start_of_chain; /* start and end of chain as constant ?? */
	Dnode end_of_chain;
	int number_of_elements;
	DestroyFunc destroyFunc_ptr;

	Dnode* get_Dnode_element(int index);

public:
    Dlist(DestroyFunc pfn=NULL);
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
	int DeleteAt(int index);    // entfernt listenelement UND payload
	void* RemoveAt(int index);  // entfernt listenelement; payload bleibt irgendwo erhalten
	int getNumberOfElements(void);
	Dnode* GetFirst(void);
	Dnode* GetLast(void);
	DestroyFunc getDestroyFuncPtr(void);
	void RefreshNumberOfElements(void);

	void* operator [](int index);
};

#endif
