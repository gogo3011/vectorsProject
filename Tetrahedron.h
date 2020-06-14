#ifndef H_TETRAHEDRON_H
#define H_TETRAHEDRON_H
#include <fstream>
#include "Point.h"
#include "EqualPointException.h"
#include "Segment.h"
#include "Triangle.h"
#include "Element.h"

class Tetrahedron : public Element
{
public:
	Tetrahedron();
	Tetrahedron(Point&, Point&, Point&, Point&);
	Tetrahedron(const Tetrahedron&);
	Tetrahedron operator=(Tetrahedron& t);
	~Tetrahedron();
	bool operator==(Point&);
	bool rightTetrahedron();
	bool ortogonalTetrahedon();
	double localArea();
	double volume();
	bool operator<(Point&);
	bool operator>(Point&);
	virtual std::ostream& ins(std::ostream& out) const;
	virtual std::ofstream& ins(std::ofstream& fstream) const;
private:
	Point p1, p2, p3, p4;

};


#endif