#include "EqualPointException.h"

const char* EqualPointException::what() const throw()
{
	return "The points in the figure are equal";
}
