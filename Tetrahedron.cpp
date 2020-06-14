#include "Tetrahedron.h"

Tetrahedron::Tetrahedron() {

}
Tetrahedron::Tetrahedron(Point& a, Point& b, Point& c, Point& d)
{
	if (a == b || a == c || a == d || b == c || b == d || c == d) {
		throw EqualPointException();
	}
	p1 = a, p2 = b, p3 = c, p4 = d;
}

Tetrahedron Tetrahedron::operator=(Tetrahedron& t) {
	p1 = t.p1;
	p2 = t.p2;
	p3 = t.p3;
	p4 = t.p4;
	return *this;
}

Tetrahedron::~Tetrahedron()
{
}

Tetrahedron::Tetrahedron(const Tetrahedron& t) {
	p1 = t.p1;
	p2 = t.p2;
	p3 = t.p3;
	p4 = t.p4;
}

bool Tetrahedron::operator==(Point& pnt)
{
	if (p1 == pnt)
		return true;
	if (p2 == pnt)
		return true;
	if (p3 == pnt)
		return true;
	if (p4 == pnt)
		return true;
	return false;
}

bool Tetrahedron::rightTetrahedron()
{
	Triangle a(p1, p2, p3);
	Triangle b(p1, p4, p3);
	Triangle c(p2, p4, p3);
	Triangle d(p1, p2, p4);
	if (a.getArea() == b.getArea() && b.getArea() == c.getArea() && c.getArea() == d.getArea()) {
		return true;
	}
	else {
		return false;
	}
}

bool Tetrahedron::ortogonalTetrahedon()
{
	Segment s1(p1, p2);
	Segment s2(p1, p3);
	Segment s3(p1, p4);
	Segment s4(p2, p3);
	Segment s5(p2, p4);
	Segment s6(p3, p4);
	if (s1 | s2 && s1 | s3 && s1 | s4 && s1 | s5 && s1 | s6 && s2 | s3 && s2 | s4 && s2 | s5 &&
		s2 | s6 && s3 | s4 && s3 | s5 && s3 | s6 && s4 | s5 && s4 | s6 && s5 | s6)
	{
		return true;
	}
	return false;
}

double Tetrahedron::localArea()
{
	Triangle A(p1, p2, p3);
	Triangle B(p1, p4, p3);
	Triangle C(p2, p4, p3);
	Triangle D(p1, p2, p4);
	double surface = A.getArea() + B.getArea() + C.getArea() + D.getArea();

	return surface;
}

double Tetrahedron::volume()
{
	//AB
	Vector v1('u', p1, p2);
	//AC
	Vector v2('u', p1, p3);
	//AD
	Vector v3('u', p1, p4);

	return v1(v2, v3) / 6.0;
}

std::ostream& Tetrahedron::ins(std::ostream& out) const
{
	return out << "====================\n"
		<< "     Tetrahedron     \n"
		<< "--------------------\n"
		<< "A = " << p1 << '\n'
		<< "B = " << p2 << '\n'
		<< "C = " << p3 << '\n'
		<< "D = " << p4 << '\n'
		<< "====================\n";
}
