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
	Line l1(v1, p1);
	cout << a.getAngle(l1);
	return 0;
}