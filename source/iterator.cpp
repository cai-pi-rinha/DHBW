#include "iterator.hpp"
#include "container.hpp"

// constructor
Iterator::Iterator()
{
	//voide
}

Iterator::Iterator(Container* container)
{
	// set the iterator onto the container and initialize all values
	imp = container;
}

///////////////////////////////////////////////////////////////////////////////////////////////////

Iterator_Impl::Iterator_Impl()
{
	
}