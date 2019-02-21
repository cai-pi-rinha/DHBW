#include "iterator.hpp"

Iterator::Iterator()
{
	//was soll hier geschehen?
	m_imp;
}

Iterator::Iterator(const Container_Interface& container)
{
	m_imp = container.CreateIteratorImp();
}

Iterator::Iterator(const Iterator& iteratorIn)
{
	//soll kopie vom iterator mit implizitem IteratorImp erzeugen
	m_imp = iteratorIn.m_imp->Clone();
}

Iterator::~Iterator()
{
	delete m_imp;
}

Iterator& Iterator::operator=(const Iterator& iterObj)
{
	if (&iterObj != this)
	{
		m_imp = iterObj.m_imp;
	}
	return *this;
}


void* Iterator::First()
{
	return m_imp->First();
}

void* Iterator::Last()
{
	return m_imp->Last();
}

void* Iterator::Prev()
{
	return m_imp->Prev();
}

void* Iterator::Next()
{
	return m_imp->Next();
}

void* Iterator::Current()
{
	return m_imp->Current();
}



///////////////////////////////////////////////////////////////////////////////////////////////////


IteratorImp::IteratorImp(const Container_Interface& owner)
{
	m_owner = &owner;
}

IteratorImp::IteratorImp(const IteratorImp& impl)
{
	m_owner = impl.m_owner;
}

IteratorImp::~IteratorImp()
{
			//dont delete owner!! 
}


