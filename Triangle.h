#ifndef H_TRIANGLE_H
#define H_TRIANGLE_H
#include "Point.h"
#include "Segment.h"
#include "TypeTrianglesEnum.h"
#include "EqualPointException.h"
#include "ArrUtils.h"
#include "Globals.h"
#include <ostream>

class Triangle: public Point
{
public:
	Triangle();
	Triangle(Point&, Point&, Point&);
	~Triangle();
	bool operator<(Point&);
	bool operator>(Point&);
	bool operator==(Point&);
	TypeTriangles getTypeByAngle();
	TypeTriangles getTypeBySides();
	double getArea();
	double getParameter();
	Point getCentroid();
	virtual std::ostream& ins(std::ostream& out) const;
	virtual std::ofstream& ins(std::ofstream& fstream) const;
private:
	Point a, b, c;
	Segment segA, segB, segC;
};

#endif