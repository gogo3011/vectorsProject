#include "Point.h"

Point::Point():letter('A'), x(0), y(0), z(0)
{
}

Point::Point(char ch, double x, double y, double z):letter(ch), x(x), y(y), z(z)
{
}

Point::Point(Point& src)
{
	letter = src.letter;
	x = src.x;
	y = src.y;
	z = src.z;
}

Point& Point::operator=(Point& src)
{
	letter = src.letter;
	x = src.x;
	y = src.y;
	z = src.z;
	return *this;
}

bool Point::operator==(Point& comp)
{
	if (x != comp.x) {
		return false;
	}
	if (y != comp.y) {
		return false;
	}
	if (z != comp.z) {
		return false;
	}
	return true;
}

void Point::print()
{
	std::cout << "Point " << letter << '\n'
		<< "x: " << x << '\n'
		<< "y: " << y << '\n'
		<< "z: " << z << '\n';
}

double Point::getX()
{
	return x;
}

double Point::getY()
{
	return y;
}

double Point::getZ()
{
	return z;
}

char Point::getLetter()
{
	return letter;
}

void Point::setLetter(char ch)
{
	letter = ch;
}
