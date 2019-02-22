#ifndef CONTAINER_H
#define CONTAINER_H

#include <iostream>
//#include "IteratorImp.hpp"

using namespace std;

class IteratorImp;  /* to be deleted if list is connected with iterator */
class Iterator;
class ContainerInterface
{
private:
    IteratorImp* myIteratorImp;
protected:
    virtual IteratorImp* CreateIteratorImp()    = 0;
public:
    ContainerInterface(void);
    ~ContainerInterface(void);
    Iterator* MakeIterator(void);
    virtual int Insert(void* payload)   = 0;
    virtual void Empty(void)            = 0;
    virtual int Count(void)             = 0;
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
