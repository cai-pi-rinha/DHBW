#include "ContainerInterface.hpp"

// constructor
ContainerInterface::ContainerInterface(void)
{
    myIteratorImp = NULL;
}

IteratorImp* ContainerInterface::CreateIteratorImp()
{

}

Iterator* ContainerInterface::MakeIterator(void)
{

}

int ContainerInterface::Insert(void* payload)
{

}

void ContainerInterface::Empty(void)
{

}

int ContainerInterface::Count(void)
{

}

void* ContainerInterface::GetAt(int index)
{

}

void* ContainerInterface::operator[](int index)
{

}
