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
Point createPoint(bool writeId = true, std::istream& in = std::cin);
Vector createVector(bool writeId = true, std::istream& in = std::cin);
Line createLine(bool writeId = true, std::istream& in = std::cin);
Segment createSegment(bool writeId = true, std::istream& in = std::cin);
Triangle createTriangle(bool writeId = true, std::istream& in = std::cin);
Tetrahedron createTetrahedron(bool writeId = true, std::istream& in = std::cin);
void pointOperations(Point&, std::istream& in = std::cin);
void vectorOperations(Vector&, std::istream& in = std::cin);
void lineOperations(Line&, std::istream& in = std::cin);
void segmentOperations(Segment&, std::istream& in = std::cin);
void triangleOperations(Triangle&, std::istream& in = std::cin);
void tetrahedronOperations(Tetrahedron&, std::istream& in = std::cin);
void readFromFile();
void writeObjToFile(Element*);
void writeObjToFile(Element*, int id);
void writeOpToFile(unsigned);
void printAllElements();
void deleteAllElements();
bool askUser(const char*);

#endif