#include "Segment.h"

Segment::Segment():Line(), paramX(0), paramY(0), paramZ(0)
{
}

Segment::Segment(Point& start, Point& end):Line(start, end)
{
	paramX = start.getX() + x;
	paramY = start.getY() + y;
	paramZ = start.getZ() + z;
}

Segment::~Segment()
{
}

Segment& Segment::operator=(Segment& src)
{
	Line::operator=(src);
	paramX = src.getFirstPoint().getX() + x;
	paramY = src.getFirstPoint().getY() + y;
	paramZ = src.getFirstPoint().getZ() + z;
	return *this;
}

bool Segment::operator==(Point& comp)
{
	Point a = getFirstPoint();
	Point b = getSecondPoint();
	double distanceToA = a + comp;
	double distanceToB = b + comp;
	double difference = (a + b) - (distanceToA + distanceToB);
	//precision
	if (difference < 0.00001 && difference > -0.00001) {
		return true;
	}
	return false;
}

double Segment::getLength()
{
	return getFirstPoint() + getSecondPoint();
}

Point Segment::getMiddlePoint()
{
	Point a = getFirstPoint();
	Point b = getSecondPoint();
	return Point('M', (a.getX() + b.getX())/2, (a.getY() + b.getY()) / 2, (a.getZ() + b.getZ()) / 2);
}
