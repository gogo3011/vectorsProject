#ifndef H_POINT_H
#define H_POINT_H
#include <iostream>
#include "element.h"

class Point : public Element {
public:
	Point();
	Point(char, double, double, double);
	Point(Point&);
	Point& operator=(Point&);
	bool operator==(Point&);
	bool operator!=(Point&);
	virtual void print();
	double getX();
	double getY();
	double getZ();
	char getLetter() const;
	void setLetter(char ch);
private:
	// name of point
	char letter;
protected:
	double x, y, z;
};

#endif // !H_POINT_H
