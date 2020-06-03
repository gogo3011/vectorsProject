#include "Line.h"

Line::Line()
{
}

Line::Line(Point& firstPoint, Point& secondPoint, char ch):Vector(ch, firstPoint, secondPoint)
{
	this->firstPoint = firstPoint;
	this->secondPoint = secondPoint;
}

Line::Line(Vector& v, Point& point):Vector(v)
{
	Point temp('a', 0, 0, 0);
	firstPoint = temp;
	secondPoint = point;
}

Vector Line::getDirectionalVector()
{
	return Vector('u', x, y, z);
}

Vector Line::getNormalVector()
{
	int x2 = 1, y2 = 1;
	double z2 = (-x * x2 - y * y2) / z;
	return Vector('n',x2, y2, z2);
}

bool Line::operator+(Point& comp)
{
	// TODO implement
	return false;
}

bool Line::operator||(Line& comp)
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

bool Line::operator==(Line& comp)
{
	if (firstPoint != comp.firstPoint) {
		return false;
	}
	if (secondPoint != comp.secondPoint) {
		return false;
	}
	return true;
}

bool Line::operator!=(Line& comp)
{
	return !(*this||comp);
}

bool Line::operator|(Line& comp)
{
	if (getAngleDegrees(comp) == 90)
		return true;
	return false;
}

double Line::getAngle(Line& comp)
{
	double a = acos(*this*(&comp) / this->length() * comp.length());
	return a;
}

double Line::getAngleDegrees(Line& comp)
{
	return getAngle(comp)* 180 / M_PI;
}
