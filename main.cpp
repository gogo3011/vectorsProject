#include <iostream>
#include "Point.h"
#include "Vector.h"
#include "Line.h"
#include "Segment.h"
#include "Triangle.h"
using namespace std;

int main() {
	Point a('a', 0, 0, 0);
	Point b('b', 1, 0, 0);
	Point c('c', 0, 0, 2.5);
	Triangle tri(a, b, c);
	Point m = tri.getCentroid();
	cout << m.getX() << "|" << m.getY() << "|" << m.getZ();
	return 0;
}