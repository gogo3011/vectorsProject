#include "Triangle.h"

Triangle::Triangle()
{
}

Triangle::Triangle(Point& A, Point& B, Point& C)
	:segA(A, B), segB(B, C), segC(C, A)
{
	if (A == B || B == C || A == C) {
		throw EqualPointException();
	}
	a = A, b = B, c = C;
}

Triangle::~Triangle()
{
}

bool Triangle::operator<(Point& cmp)
{
	Triangle firstPart(a, b, cmp),
		secoundPart(b,c,cmp),
		thirdPart(c,a,cmp);
	double fullArea = firstPart.getArea() + secoundPart.getArea() + thirdPart.getArea();
	if (this->getArea() - fullArea < TOLERANCE) {
		return true;
	}
	return false;
}

bool Triangle::operator>(Point& cmp)
{
	if (*this < cmp)
		return false;
	Vector first('a', a, b), secound('b', a, c);
	Vector normal(first ^ secound);
	double independentTerm = -(normal.getX() * a.getX() + normal.getY() * a.getY() + normal.getZ() * a.getZ());
	if (abs((normal.getX() * cmp.getX() + normal.getY() * cmp.getY() + normal.getZ() * cmp.getZ()) + independentTerm) < TOLERANCE)
		return true;
	return false;
}

bool Triangle::operator==(Point& cmp)
{
	if (segA == cmp)
		return true;
	if (segB == cmp)
		return true;
	if (segC == cmp)
		return true;
	return false;
}

TypeTriangles Triangle::getTypeByAngle()
{
	double angles[3];
	angles[0] = segC.getAngleDegrees(segA);
	angles[1] = segA.getAngleDegrees(segB);
	angles[2] = segB.getAngleDegrees(segC);
	double maxAng = getMax<double, 3>(angles);
	if (maxAng == 90) {
		return TypeTriangles(rectangular);
	}
	else if (maxAng > 90) {
		return TypeTriangles(obtuse);
	}
	else
	{
		return TypeTriangles(isosceles);
	}
}

TypeTriangles Triangle::getTypeBySides()
{
	double sidesLength[3]{segA.getLength(),segB.getLength(), segC.getLength() };
	// first 3 types in TypeTriangle correspong to the number of equal sides found
	return TypeTriangles(getEquCnt<double, 3>(sidesLength));
}

double Triangle::getArea()
{
	return (segA.getLength()*segC.getLength()*sin(segC.getAngle(segA)))/2;
}

double Triangle::getParameter()
{
	return segA.getLength() + segB.getLength() + segC.getLength();
}

Point Triangle::getCentroid()
{
	double 
		arrX[3]{ a.getX(), b.getX(), c.getX() } ,
		arrY[3]{ a.getY(), b.getY(), c.getY() },
		arrZ[3]{ a.getZ(), b.getZ(), c.getZ() };
	return Point('M',getAverage<double, 3>(arrX),
		getAverage<double, 3>(arrY),
		getAverage<double, 3>(arrZ));
}

std::ostream& Triangle::ins(std::ostream& out) const
{
	return out << "A = " << a << '\n'
		<< "B = " << b << '\n'
		<< "C = " << c << '\n';
}
