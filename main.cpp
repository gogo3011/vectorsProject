#include <iostream>
#include "Point.h"
#include "Vector.h"
#include "Line.h"
using namespace std;

int main() {
	Vector v('v', 3, 6, 3);
	Point p('p', 3, 6, 3);
	Line a(v, p);
	Vector v1('b', 1, 1, -3);
	Point p1('n', 1, 1, -3);
	Point p2('c', 0, 0, 0);
	Point p3('d', 3, 6, 4);
	Line c(v1, p2);
	Line l1(a);
	cout <<(a|c);
	return 0;
}