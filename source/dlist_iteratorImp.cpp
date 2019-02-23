#include"dlist_iteratorImp.hpp"
#include "DList.hpp"

Dlist_IteratorImp::Dlist_IteratorImp(const DList& owner) : IteratorImp()//doppelpunkt ruft konstruktor der basisklasse auf (passiert sowieso)
{
	//konstruktor ruft als erstes konstruktor von basisklasse auf
	m_current = owner.GetFirst();
}

Dlist_IteratorImp::Dlist_IteratorImp(const Dlist_IteratorImp& DlistIt) : IteratorImp(*m_owner)
{
	
	m_current = DlistIt.m_current;
}

Dlist_IteratorImp::~Dlist_IteratorImp()
{
				//es muss nichts gelöscht werden
}

void Dlist_IteratorImp::set(DNode* dnode)
{
	m_current = dnode;
}

void* Dlist_IteratorImp::Current()
{
	return m_current != NULL ? m_current->GetObject() : NULL;
}

void* Dlist_IteratorImp::Next()
{
	if(m_current)
		m_current = m_current->GetNext();
	return m_current != NULL ? m_current->GetObject() : NULL;
}

void* Dlist_IteratorImp::Prev()
{

	if (m_current)
		m_current = m_current->GetPrev();
	return m_current != NULL ? m_current->GetObject(): NULL;
}


void* Dlist_IteratorImp::Last()
{

	if (m_current)
	{
		while (m_current->GetNext())	//count until next is NULL -> last element
			m_current = m_current->GetNext();
	}
	return m_current != NULL ? m_current->GetObject() : NULL;
}

void* Dlist_IteratorImp::First()
{

	if (m_current)
	{
		while (m_current->GetPrev())	//count until previous is NULL -> first element
			m_current = m_current->GetPrev();
	}
	return m_current != NULL ? m_current->GetObject() : NULL;
}
Dlist_IteratorImp* Dlist_IteratorImp::Clone()
{
	return new Dlist_IteratorImp(*this);
}
