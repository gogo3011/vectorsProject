#include "Vector.h"

Vector::Vector():Point('u', 1, 1, 1)
{
}

// x, y ,z == I, J, K koeficienti
Vector::Vector(char ch, double x, double y, double z):Point(ch, x, y, z)
{
}

Vector::Vector(char ch, Point& a, Point& b)
{
	x = b.getX() - a.getX();
	y = b.getY() - a.getY();
	z = b.getZ() - a.getZ();
	setLetter('u');
}

Vector::Vector(const Vector& src)
{
	x = src.x;
	y = src.y;
	z = src.z;
	setLetter(src.getLetter());
}

Vector& Vector::operator=(Vector& src)
{
	setLetter(src.getLetter());
	x = src.x;
	y = src.y;
	z = src.z;
	return *this;
}

double Vector::length() const
{
	return sqrt(x*x + y*y + z*z);
}

Vector Vector::direction(char letter) const
{
	double divider = this->length();
	if (divider <= 0)
		throw VectorLengthException();
	return Vector(letter, x/divider, y/divider, z/divider);
}

void Vector::setX(double x)
{
	this->x = x;
}

void Vector::setY(double y)
{
	this->y = y;
}

void Vector::setZ(double z)
{
	this->z = z;
}

double Vector::getX() const
{
	return x;
}

double Vector::getY() const
{
	return y;
}

double Vector::getZ() const
{
	return z;
}

bool Vector::isZero() const
{
	if (x + y + z == 0)
		return true;
	return false;
}

bool Vector::isParallelTo(Vector* comp) const
{
	if (comp->length() == 0 || this->length() == 0)
		throw new VectorLengthException;
	double xRatio = x / comp->x;
	double yRatio = y / comp->y;
	double zRatio = z / comp->z;
	if ((xRatio == yRatio) == zRatio) {
		return true;
	}
	return false;
}

bool Vector::isPerpendicularTo(Vector* comp) const
{
	if (comp->isZero() || this->isZero())
		throw new VectorLengthException;
	double xTemp = x * comp->x;
	double yTemp = y * comp->y;
	double zTemp = z * comp->z;
	if (xTemp + yTemp + zTemp == 0) {
		return true;
	}
	return false;
}

Vector Vector::operator+(Vector* rhs) const
{
	return Vector('q', x + rhs->x, y + rhs->y, z + rhs->z);
}

Vector Vector::operator-(Vector* rhs) const
{
	return Vector('q', x - rhs->x, y - rhs->y, z - rhs->z);
}

Vector Vector::operator*(double r) const
{
	return Vector('q', x*r, y*r, z*r);
}

double Vector::operator*(Vector* rhs) const
{
	return x*rhs->x + y * rhs->y + z * rhs->z;
}

Vector Vector::operator^(Vector* rhs) const
{
	return Vector('q', y*rhs->z - z*rhs->y, z * rhs->x - x * rhs->z, x * rhs->y - y * rhs->x);
}