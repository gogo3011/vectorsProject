#ifndef H_LINE_H
#define H_LINE_H
#include "Point.h"
#include "Vector.h"

class Line : public Vector {
public:
	Line();
	Line(Point&, Point&, char ch = 'u');
	Line(Vector&, Point&);
	Vector getDirectionalVector();
	Vector getNormalVector();
	double getAngle(Line&);

private:
	Point firstPoint;
	Point secondPoint;

};
#endif