#ifndef ITERATOR_H
#define ITERATOR_H

#include "container_interface.hpp"
#include <stdio.h>

class Iterator 
{
private:
	IteratorImp* m_imp = NULL;		//bringt tatsächlich nichts, wird im konstrutkor initialisiert
	
public:
	Iterator();
	Iterator(const Container_Interface& container);
	Iterator(const Iterator& iterator);
	~Iterator();
	Iterator& operator=(const Iterator& iterObj);
	void* First();
	void* Last();
	void* Prev();
	void* Next();
	void* Current();
};

class IteratorImp 
{
private:
	const Container_Interface* m_owner = NULL;

protected:
	IteratorImp(const Container_Interface& owner);
	IteratorImp(const IteratorImp& implementation);
	
public:
	IteratorImp* Clone();
	virtual ~IteratorImp() = 0;
	virtual void* First() = 0;
	virtual void* Last() = 0;
	virtual void* Prev() = 0;
	virtual void* Next() = 0;
	virtual void* Current() = 0;
    
	//virtual Dnode* current(void)	= 0;
	/*	This is a pure virtual function. Used when there
	 *	is no sensible default implementation for that method.
	 *	This means, that subclasses have to implement this
	 *	function, otherwise they are abstract, meaning you
	 *	cannot create objects of that class.
	 */
};


#endif
