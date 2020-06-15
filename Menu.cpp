#include "Menu.h"

Element* objArr[100];
unsigned objCnt = 0;

int menu()
{
	unsigned choice;
	char againOperationQ[] = "Issue a new operation?";
	char newObjQ[] = "Create a new object?";
	do
	{
		std::cout << "Please, select a geometric object: \n"
			<< "1. Point\n"
			<< "2. Vector\n"
			<< "3. Line\n"
			<< "4. Segment\n"
			<< "5. Triangle\n"
			<< "6. Tetrahedron\n"
			<< "7. Print all created elements\n"
			<< "8. Read your last operation from a file\n";
		std::cin >> choice;
		switch (choice)
		{
		case 1:
		{
			Point p(createPoint());
			do
			{
				pointOperations(p);
			} while (askUser(againOperationQ));
			break;
		}
		case 2:
		{
			Vector v(createVector());
			do
			{
				vectorOperations(v);
			} while (askUser(againOperationQ));
			break;
		}
		case 3:
		{
			Line l(createLine());
			do
			{
				lineOperations(l);
			} while (askUser(againOperationQ));
			break;
		}
		case 4:
		{
			Segment s(createSegment());
			do
			{
				segmentOperations(s);
			} while (askUser(againOperationQ));
			break;
		}
		case 5:
		{
			Triangle t(createTriangle());
			do
			{
				triangleOperations(t);
			} while (askUser(againOperationQ));
			break;
		}
		case 6:
		{
			Tetrahedron t(createTetrahedron());
			do
			{
				tetrahedronOperations(t);
			} while (askUser(againOperationQ));
		}
		case 7:
		{
			printAllElements();
			break;
		}
		case 8:
		{
			readFromFile();
			break;
		}
		default:
			std::cout << "Invalid menu option..." << '\n';
			break;
		}
		} while (askUser(newObjQ));
	deleteAllElements();
	return 0;
}

Point createPoint(bool writeId, std::istream& in)
{
	double x, y, z;
	std::cout << "Please, enter x coordinate: \n";
	in >> x;
	std::cout << "Please, enter y coordinate: \n";
	in >> y;
	std::cout << "Please, enter z coordinate: \n";
	in >> z;
	Point obj('u', x, y, z);
	objArr[objCnt++] = new Point(obj);
	if (writeId)
		writeObjToFile(&obj, 1);
	else
		writeObjToFile(&obj);
	return obj;
}

void pointOperations(Point& curr, std::istream& in) {
	unsigned opt;
	std::cout << "Avalable Point operations: \n"
		<< "1. Print object\n";
	in >> opt;
	if (opt == 1) {
		writeOpToFile(opt);
	switch (opt)
	{
	case 1: 
	{
		std::cout << curr << '\n';
		break;
	}
	default:
		std::cout << "Invalid input";
		break;
	}
	}
}


Vector createVector(bool writeId, std::istream& in)
{
	double x, y, z;
	std::cout << "Please, enter x coordinate: \n";
	in >> x;
	std::cout << "Please, enter y coordinate: \n";
	in >> y;
	std::cout << "Please, enter z coordinate: \n";
	in >> z;
	Vector obj('u', x, y, z);
	writeObjToFile(&obj, 2);
	objArr[objCnt++] = new Vector(obj);
	if (writeId)
		writeObjToFile(&obj, 2);
	else
		writeObjToFile(&obj);
	return obj;
}

void vectorOperations(Vector& curr, std::istream& in)
{
	unsigned opt;
	std::cout << "Avalable Vector operations: \n"
		<< "1. Get length\n"
		<< "2. Get directional vector\n"
		<< "3. Check if vector is zero\n"
		<< "4. Check if vector is parallel w. new vector\n"
		<< "5. Check if vector is perpendicular w. new vector\n"
		<< "6. Make a sum w. new vector \n"
		<< "7. Multiply vector w. a real number \n"
		<< "8. Scalar multiplication w. new vector \n"
		<< "9. Vector multiplication w. new vector \n"
		<< "10. Mixed multiplication w. 2 new vectors \n";
	in >> opt;
	if(opt <= 10  && opt > 0){
		writeOpToFile(opt);
	switch (opt)
	{
	case 1:
	{
		std::cout << curr.length() << '\n';
		break;
	}
	case 2:
	{
		std::cout << curr.direction() << '\n';
		break;
	}
	case 3:
	{
		std::cout << (std::boolalpha) << curr.isZero() << '\n';
		break;
	}
	case 4:
	{
		Vector newV(createVector(false, in));
		std::cout << (std::boolalpha) << curr.isParallelTo(&newV) << '\n';
		break;
	}
	case 5:
	{
		Vector newV(createVector(false, in));
		std::cout << (std::boolalpha) << curr.isPerpendicularTo(&newV) << '\n';
		break;
	}
	case 6:
	{
		Vector newV(createVector(false, in));
		std::cout << (std::boolalpha) << curr + &newV << '\n';
		break;
	}
	case 7:
	{
		double multiply;
		std::cout << "Please, enter the multiplier: \n";
		std::cin.ignore();
		std::cin >> multiply;
		std::cout << curr * multiply;
		break;
	}
	case 8:
	{
		Vector newV(createVector(false, in));
		std::cout << curr * newV << '\n';
		break;
	}
	case 9:
	{
		Vector newV(createVector(false, in));
		std::cout << curr.operator^(newV) << '\n';
		break;
	}
	case 10:
	{
		Vector newV1(createVector(false, in));
		Vector newV2(createVector(false, in));
		std::cout << curr(newV1, newV2) << '\n';
		break;
	}
	default:
		break;
	}
	}
}


Line createLine(bool writeId, std::istream& in)
{
	std::cout << "Creating Line... \n";
	Point first(createPoint(writeId, in)), secound(createPoint(writeId, in));
	Line obj(first, secound);
	objArr[objCnt++] = new Line(obj);
	if (writeId)
		writeObjToFile(&obj, 3);
	else
		writeObjToFile(&obj);
	return obj;
}

void lineOperations(Line& curr, std::istream& in)
{
	unsigned opt;
	std::cout << "Avalable Line operations: \n"
		<< "1. Get normal vector\n"
		<< "2. Get directional vector\n"
		<< "3. Get angle between new line\n"
		<< "4. Check if new Point lies on Line\n"
		<< "5. Check if Line is parallel with new Line\n"
		<< "6. Check if Line equals new Line\n"
		<< "7. Check if Line intercepts w. new Line \n"
		<< "8. Check if Line is perpendicular w. new Line \n";
	in >> opt;
	if (opt > 0 && opt <= 8) {
		writeOpToFile(opt);
	switch (opt)
	{
	case 1:
	{
		std::cout << curr.getNormalVector() << '\n';
		break;
	}
	case 2:
	{
		std::cout << curr.getDirectionalVector() << '\n';
		break;
	}
	case 3:
	{
		Line newl(createLine(false));
		std::cout << curr.getAngleDegrees(newl) << '\n';
		break;
	}
	case 4:
	{
		Point newp(createPoint(false));
		std::cout << (std::boolalpha) << curr + newp << '\n';
	}
	case 5:
	{
		Line newl(createLine(false));
		std::cout << (std::boolalpha) << curr.operator||(newl) << '\n';
		break;
	}
	case 6:
	{
		Line newl(createLine(false));
		std::cout << (std::boolalpha) << curr.operator==(newl) << '\n';
		break;
	}
	case 7:
	{
		Line newl(createLine(false));
		std::cout << (std::boolalpha) << curr.operator!=(newl) << '\n';
		break;
	}
	case 8:
	{
		Line newl(createLine(false));
		std::cout << (std::boolalpha) << curr.operator|(newl) << '\n';
		break;
	}
	default:
		break;
	}
	}
}

Segment createSegment(bool writeId, std::istream& in)
{
	std::cout << "Creating Segment..." << '\n';
	Point first(createPoint(false, in)), secound(createPoint(false, in));
	Segment obj(first, secound);
	objArr[objCnt++] = new Segment(obj);
	if (writeId)
		writeObjToFile(&obj, 4);
	else
		writeObjToFile(&obj);
	return obj;
}

void segmentOperations(Segment& curr, std::istream& in)
{
	unsigned opt;
	std::cout << "Avalable Segment operations: \n"
		<< "1. Get length\n"
		<< "2. Get middle Point\n"
		<< "3. Check if Point lies on Segment\n";
	in >> opt;
	if (opt > 0 && opt <= 3) {
		writeOpToFile(opt);
	switch (opt)
	{
	case 1: 
	{
		std::cout << curr.getLength() << '\n';
		break;
	}
	case 2:
	{
		Point p(curr.getMiddlePoint());
		std::cout << p << '\n';
		break;
	}
	case 3:
	{
		Point p(createPoint(false, in));
		std::cout << (std::boolalpha) << curr.operator==(p) << '\n';
		break;
	}
	default:
		break;
	}
	}
}

Triangle createTriangle(bool writeId, std::istream& in)
{
	bool valid = false;
	do
	{
		try
		{
			std::cout << "Creating Triangle...\n";
			Point p1(createPoint(false, in)), p2(createPoint(false, in)), p3(createPoint(false, in));
			Triangle t(p1, p2, p3);
			objArr[objCnt++] = new Triangle(t);
			if (writeId)
				writeObjToFile(&t, 5);
			else
				writeObjToFile(&t);
			valid = true;
			return t;
		}
		catch (const EqualPointException& ex)
		{
			std::cout << ex.what() << '\n';
			valid = false;
		}
	} while (!valid);
}


void triangleOperations(Triangle& curr, std::istream& in)
{
	unsigned opt;
	std::cout << "Avalable Triangle operations: \n"
		<< "1. Get type of triangle\n"
		<< "2. Get surface area\n"
		<< "3. Get parameter\n"
		<< "4. Get middle Point of triangle\n"
		<< "5. Check if Point lies inside Triangle\n"
		<< "6. Check if Point lies in Plane, but not inside Triangle\n"
		<< "7. Check if Point lies on a Segment of Triangle \n";
	in >> opt;
	if (opt > 0 && opt <= 7) {
		writeOpToFile(opt);
	switch (opt)
	{
	case 1:
	{
		TypeTriangles byAngle = curr.getTypeByAngle();
		switch (byAngle)
		{
		case acute:
			std::cout << "Acute | ";
			break;
		case rectangular:
			std::cout << "Rectangular | ";
			break;
		case obtuse:
			std::cout << "Obtuse | ";
			break;
		default:
			break;
		}
		TypeTriangles bySides = curr.getTypeBySides();
		switch (bySides)
		{
		case diffrent:
			std::cout << "Sides are diffrent\n";
			break;
		case isosceles:
			std::cout << "Isosceles\n";
			break;
		case equilateral:
			std::cout << "Equilateral\n";
			break;
		default:
			break;
		}
		break;
	}
	case 2:
	{
		std::cout << curr.getArea()<< '\n';
		break;
	}
	case 3:
	{
		std::cout << curr.getParameter() << '\n';
		break;
	}
	case 4:
	{
		Point m(curr.getCentroid());
		std::cout << m << '\n';
		break;
	}
	case 5:
	{
		Point p(createPoint(false, in));
		std::cout << (std::boolalpha) << curr.operator<(p) << '\n';
		break;
	}
	case 6:
	{
		Point p(createPoint(false, in));
		std::cout << (std::boolalpha) << curr.operator>(p) << '\n';
		break;
	}
	case 7:
	{
		Point p(createPoint(false, in));
		std::cout << (std::boolalpha) << curr.operator==(p) << '\n';
		break;
	}
	default:
		break;
	}
	}
}


Tetrahedron createTetrahedron(bool writeId, std::istream& in)
{
	bool valid = false;
	do
	{
		try
		{
			std::cout << "Creating Tetrahedron...\n";
			Point p1(createPoint(false, in)), p2(createPoint(false, in)), p3(createPoint(false, in)), p4(createPoint(false, in));
			Tetrahedron t(p1, p2, p3, p4);
			objArr[objCnt++] = new Tetrahedron(t);
			valid = true;
			if (writeId)
				writeObjToFile(&t, 6);
			else
				writeObjToFile(&t);
			return Tetrahedron();
		}
		catch (const EqualPointException & ex)
		{
			std::cout << ex.what() << '\n';
			valid = false;
		}
	} while (!valid);
	Point p1(createPoint()), p2(createPoint()), p3(createPoint()), p4(createPoint());
	Tetrahedron t(p1, p2, p3, p4);
	objArr[objCnt++] = new Tetrahedron(t);
	return Tetrahedron();
}

void tetrahedronOperations(Tetrahedron& curr, std::istream& in)
{
	unsigned opt;
	std::cout << "Avalable Tetrahedron operations: \n"
		<< "1. Check if it's \'right\'\n"
		<< "2. Check if it's ortogonal\n"
		<< "3. Get surface area\n"
		<< "4. Get volume\n"
		<< "5. Check if point is on sides\n";
	in >> opt;
	if (opt > 0 && opt <= 5) {
		writeOpToFile(opt);
	switch (opt)
	{
	case 1:
	{
		std::cout << (std::boolalpha) << curr.rightTetrahedron() << '\n';
		break;
	}
	case 2:
	{
		std::cout << (std::boolalpha) << curr.ortogonalTetrahedon() << '\n';
		break;
	}
	case 3:
	{
		std::cout << curr.localArea() << '\n';
		break;
	}
	case 4:
	{
		std::cout << curr.volume() << '\n';
		break;
	}
	default:
		break;
	}
	}
}

void readFromFile()
{
	unsigned objId;
	std::ifstream file("lastOp.txt");
	file >> objId;
	switch (objId)
	{
	case 1: {
		Point p(createPoint(true, file));
		pointOperations(p, file);
		break;
	}
	case 2: {
		Vector v(createVector(true, file));
		vectorOperations(v, file);
		break;
	}
	case 3: {
		Line l(createLine(true, file));
		lineOperations(l, file);
		break;
	}
	case 4: {
		Segment s(createSegment(true, file));
		segmentOperations(s, file);
		break;
	}
	case 5: {
		Triangle t(createTriangle(true, file));
		triangleOperations(t, file);
		break;
	}
	case 6: {
		Tetrahedron t(createTetrahedron(true, file));
		tetrahedronOperations(t, file);
		break;
	}
	default:
		break;
	}
}

void writeObjToFile(Element* curr)
{
	std::ofstream file("lastOp.txt", std::ios_base::app);
	if (file.is_open()) {
		file << *curr << '\n';
	}
}

void writeObjToFile(Element* curr, int id)
{
	std::ofstream file("lastOp.txt");
	if (file.is_open()) {
		file << id << '\n';
		file << *curr << '\n';
	}
}

void writeOpToFile(unsigned opId)
{
	std::ofstream file("lastOp.txt", std::ios_base::app);
	if (file.is_open()) {
		file << opId << '\n';
	}
}

void printAllElements()
{
	for (size_t i = 0; i < objCnt; i++)
	{
		std::cout << *objArr[i] << '\n';
	}
}

void deleteAllElements()
{
	for (size_t i = 0; i < objCnt; i++)
	{
		if (objArr[i] != nullptr){
			delete objArr[i];
			objArr[i] = nullptr;
		}
	}
}

bool askUser(const char* q)
{
	do
	{
		char a;
		std::cout << q << " (y/n)\n";
		std::cin >> a;
		if (a == 'y') {
			return true;
		}
		if (a == 'n') {
			return false;
		}
	} while (true);
	return false;
}
