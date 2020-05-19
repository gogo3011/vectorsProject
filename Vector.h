#ifndef H_VECTOR_H
#define H_VECTOR_H
#include "Point.h"
#include "VectorLengthException.h"

class Vector : public Point {
public:
	Vector();
	Vector(char,double, double, double);
	Vector(char, Point&, Point&);
	Vector(const Vector&);
	Vector& operator=(Vector&);
	double length() const;
	Vector direction(char letter = '1') const;
	void setX(double x);
	void setY(double y);
	void setZ(double z);
	double getX() const;
	double getY() const;
	double getZ() const;
	bool isZero() const;
	bool isParallelTo(Vector*) const;
	bool isPerpendicularTo(Vector*) const;
	Vector operator+(Vector*) const;
	Vector operator-(Vector*) const;
	Vector operator*(double) const;
	double operator*(Vector*) const;
	Vector operator^(Vector*) const;
	double operator()(Vector& v1, Vector& v2) const;
};

#endif // !H_VECTOR_H
