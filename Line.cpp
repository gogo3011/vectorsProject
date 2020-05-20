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

 //fix implementation
double Line::getAngle(Line& comp)
{
	double a = this->operator*(&comp) / this->length() * comp.length();
	return a;
}
