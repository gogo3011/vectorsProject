#ifndef H_SEGMENT_H
#define H_SEGMENT_H
#include "Line.h"
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
private:
	double paramX, paramY, paramZ;
};

#endif