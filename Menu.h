#ifndef H_MENU_H
#define H_MENU_H
#include <iostream>
#include <fstream>
#include "Point.h"
#include "Vector.h"
#include "Line.h"
#include "Segment.h"
#include "Triangle.h"
#include "Tetrahedron.h"
#include "EqualPointException.h"
#include "TypeTrianglesEnum.h"

int menu();
Point createPoint(bool writeId = true);
Vector createVector(bool writeId = true);
Line createLine(bool writeId = true);
Segment createSegment(bool writeId = true);
Triangle createTriangle(bool writeId = true);
Tetrahedron createTetrahedron(bool writeId = true);
void pointOperations(Point&);
void vectorOperations(Vector&);
void lineOperations(Line&);
void segmentOperations(Segment&);
void triangleOperations(Triangle&);
void tetrahedronOperations(Tetrahedron&);
void writeObjToFile(Element*);
void writeObjToFile(Element*, int id);
void writeOpToFile(unsigned);
void printAllElements();
void deleteAllElements();
bool askUser(const char*);

#endif