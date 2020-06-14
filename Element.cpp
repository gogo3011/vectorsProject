#include "Element.h"

std::ostream& operator<<(std::ostream& out, const Element& rhs)
{
	return rhs.ins(out);
}

std::ofstream& operator<<(std::ofstream& out, const Element& rhs)
{
	return rhs.ins(out);
}

