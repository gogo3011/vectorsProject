#ifndef H_MENU_H
#define H_MENU_H
#include <iostream>
#include "Point.h"
#include "Vector.h"
#include "Line.h"
#include "Segment.h"
#include "Triangle.h"
#include "Tetrahedron.h"
#include "EqualPointException.h"
#include "TypeTrianglesEnum.h"

int menu();
Point createPoint();
Vector createVector();
Line createLine();
Segment createSegment();
Triangle createTriangle();
Tetrahedron createTetrahedron();
void pointOperations(Point&);
void vectorOperations(Vector&);
void lineOperations(Line&);
void segmentOperations(Segment&);
void triangleOperations(Triangle&);
void tetrahedronOperations(Tetrahedron&);
void printAllElements();
void deleteAllElements();
bool askUser(const char*);

#endif