#include"dlist_iteratorImp.hpp"


Dlist_IteratorImp::Dlist_IteratorImp(const Dlist DList& owner) : IteratorImp(owner) //doppelpunkt ruft konstruktor der basisklasse auf (passiert sowieso)
{
	//konstruktor ruft als erstes konstruktor von basisklasse auf
	m_current = owner.GetFirst();
}

Dlist_IteratorImp::~Dlist_IteratorImp()
{
				//es muss nichts gelöscht werden
}

void Dlist_IteratorImp::set(Dnode* dnode)
{
	m_current = dnode;
}

void* Dlist_IteratorImp::Current()
{
	return m_current != NULL ? m_current->get_payload() : NULL;
}

void* Dlist_IteratorImp::Next()
{
	if(m_current)
		m_current = m_current->get_next();
	return m_current != NULL ? m_current->get_payload() : NULL;
}

void* Dlist_IteratorImp::Prev()
{

	if (m_current)
		m_current = m_current->get_prev();
	return m_current != NULL ? m_current->get_payload(): NULL;
}


void* Dlist_IteratorImp::Last()
{

	if (m_current)
	{
		while (m_current->get_next())	//count until next is NULL -> last element
			m_current = m_current->get_next();
	}
	return m_current != NULL ? m_current->get_payload() : NULL;
}

void* Dlist_IteratorImp::First()
{

	if (m_current)
	{
		while (m_current->get_prev())	//count until previous is NULL -> first element
			m_current = m_current->get_prev();
	}
	return m_current != NULL ? m_current->get_payload() : NULL;
}
void* Dlist_IteratorImp::Clone()
{
	return new Dlist_IteratorImp(*this);
}
