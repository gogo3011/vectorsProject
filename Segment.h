#ifndef H_SEGMENT_H
#define H_SEGMENT_H
#include "Line.h"
#include "Globals.h"
#include <ostream>
#include <fstream>

class Segment : public Line
{
public:
	Segment();
	Segment(Point&, Point&);
	~Segment();
	Segment& operator=(Segment&);
	bool operator==(Point&);
	double getLength();
	Point getMiddlePoint();
	virtual std::ostream& ins(std::ostream& out) const;
	virtual std::ofstream& ins(std::ofstream& fstream) const;
private:
	double paramX, paramY, paramZ;
};

#endif