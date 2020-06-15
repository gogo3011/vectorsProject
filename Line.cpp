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

Line::Line(const Line& src):Vector(src)
{
	firstPoint = src.firstPoint;
	secondPoint = src.secondPoint;
}

Vector Line::getDirectionalVector()
{
	return Vector('u', x, y, z);
}


Vector Line::getNormalVector()
{
	return Vector('n', firstPoint.getX() - secondPoint.getX(),
		firstPoint.getY() - secondPoint.getY(),
		firstPoint.getZ() - secondPoint.getZ());
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
	double a = (*this*(comp)) / (this->length() * comp.length());
	return acos(abs(a));
}

double Line::getAngleDegrees(Line& comp)
{
	return getAngle(comp)* 180 / M_PI;
}

Point& Line::getFirstPoint()
{
	return firstPoint;
}

Point& Line::getSecondPoint()
{
	return secondPoint;
}

std::ostream& Line::ins(std::ostream& out) const
{
	return out << "====================\n"
		<< "        Line     \n"
		<< "--------------------\n"
		<< "First Point: " << firstPoint << '\n'
		<< "Second Point: " << secondPoint << '\n'
		<< "====================\n";
}

std::ofstream& Line::ins(std::ofstream& fstream) const
{
	fstream << firstPoint << '\n';
	fstream << secondPoint;
	return fstream;
}
