#ifndef H_POINT_H
#define H_POINT_H
#include <iostream>
#include "element.h"

class Point : public Element {
public:
	Point();
	Point(char, double, double, double);
	Point(const Point&);
	Point& operator=(const Point&);
	bool operator==(Point&);
	bool operator!=(Point&);
	//finds distance between two points
	double operator+(Point&);
	virtual void print();
	double getX();
	double getY();
	double getZ();
	char getLetter() const;
	void setLetter(char ch);
	virtual std::ostream& ins(std::ostream& out) const;
	virtual std::ofstream& ins(std::ofstream& fstream) const;
private:
	// name of point
	char letter;
protected:
	double x, y, z;
};

#endif // !H_POINT_H
