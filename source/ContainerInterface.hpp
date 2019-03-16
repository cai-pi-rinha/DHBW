#ifndef CONTAINER_H
#define CONTAINER_H

#include "iterator.hpp"

class ContainerInterface 
{
private:
	
public:
	ContainerInterface();
	~ContainerInterface();
	Iterator* MakeIterator() const;
	virtual IteratorImp* CreateIteratorImp() const = 0;
	virtual int Insert(void* payload)   = 0;
	virtual void Empty()				= 0;
	virtual int Count()	const			= 0;
	virtual void* GetAt(int index)      = 0;
	virtual void* operator[](int index) = 0;
	/*	'= 0';
		*	This is a pure virtual function. Used when there
		*	is no sensible default implementation for that method.
		*	This means, that subclasses have to implement this
		*	function, otherwise they are abstract, meaning you
		*	cannot create objects of that class.
		*/
};

#endif
