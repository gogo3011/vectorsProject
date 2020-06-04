#ifndef H_TRIANGLE_H
#define H_TRIANGLE_H
#include "Point.h"
#include "Segment.h"
#include "TypeTrianglesEnum.h"
#include "EqualPointException.h"
#include "ArrUtils.h"

class Triangle: public Point
{
public:
	Triangle();
	Triangle(Point&, Point&, Point&);
	~Triangle();
	bool operator==(Point&);
	TypeTriangles getTypeByAngle();
	TypeTriangles getTypeBySides();
	double getArea();
	double getParameter();
	Point getCentroid();
private:
	Point a, b, c;
	Segment segA, segB, segC;
};

#endif