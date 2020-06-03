#ifndef H_LINE_H
#define H_LINE_H
#include "Point.h"
#include "Vector.h"
# define M_PI           3.14159265358979323846

class Line : public Vector {
public:
	Line();
	Line(Point&, Point&, char ch = 'u');
	Line(Vector&, Point&);
	Vector getDirectionalVector();
	Vector getNormalVector();
	bool operator+(Point&);
	bool operator||(Line&);
	bool operator==(Line&);
	bool operator!=(Line&);
	bool operator|(Line&);
	double getAngle(Line&);
	double getAngleDegrees(Line&);

private:
	Point firstPoint;
	Point secondPoint;

};
#endif