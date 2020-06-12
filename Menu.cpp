#include "Menu.h"

int menu()
{
	unsigned choice;
	// Element** elements;
	char againOperationQ[] = "Issue a new operation?";
	char newObjQ[] = "Create a new object?";
	do
	{
	std::cout << "Please, select a geometric object: \n"
		<< "1. Point\n"
		<< "2. Vector\n"
		<< "3. Line\n"
		<< "4. Segment\n"
		<< "5. Triangle\n";
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
	default:
		std::cout << "Invalid menu option..." << '\n';
		break;
	}
	} while (askUser(newObjQ));
	return 0;
}

Point createPoint()
{
	char ch;
	double x, y, z;
	std::cout << "Please, enter x coordinate: \n";
	std::cin.ignore();
	std::cin >> x;
	std::cout << "Please, enter y coordinate: \n";
	std::cin.ignore();
	std::cin >> y;
	std::cout << "Please, enter z coordinate: \n";
	std::cin.ignore();
	std::cin >> z;
	return Point('u', x, y, z);
}

void pointOperations(Point& curr) {
	unsigned opt;
	std::cout << "Avalable Point operations: \n"
		<< "1. Print object\n";
	std::cin.ignore();
	std::cin >> opt;
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


Vector createVector()
{
	char ch;
	double x, y, z;
	std::cout << "Please, enter a letter for your Vector: \n";
	std::cin.ignore();
	std::cin >> ch;
	std::cout << "Please, enter x coordinate: \n";
	std::cin.ignore();
	std::cin >> x;
	std::cout << "Please, enter y coordinate: \n";
	std::cin.ignore();
	std::cin >> y;
	std::cout << "Please, enter z coordinate: \n";
	std::cin.ignore();
	std::cin >> z;
	return Vector(ch, x, y, z);
}

void vectorOperations(Vector& curr)
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
	std::cin.ignore();
	std::cin >> opt;
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
		Vector newV(createVector());
		std::cout << (std::boolalpha) << curr.isParallelTo(&newV) << '\n';
		break;
	}
	case 5:
	{
		Vector newV(createVector());
		std::cout << (std::boolalpha) << curr.isPerpendicularTo(&newV) << '\n';
		break;
	}
	case 6:
	{
		Vector newV(createVector());
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
		Vector newV(createVector());
		std::cout << curr * newV << '\n';
		break;
	}
	case 9:
	{
		Vector newV(createVector());
		std::cout << curr.operator^(newV) << '\n';
		break;
	}
	case 10:
	{
		Vector newV1(createVector());
		Vector newV2(createVector());
		std::cout << curr(newV1, newV2) << '\n';
		break;
	}
	default:
		break;
	}
}


Line createLine()
{
	std::cout << "Creating Line... \n";
	Point first(createPoint()), secound(createPoint());
	return Line(first, secound);
}

void lineOperations(Line& curr)
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
	std::cin.ignore();
	std::cin >> opt;
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
		Line newl(createLine());
		std::cout << curr.getAngleDegrees(newl) << '\n';
		break;
	}
	case 4:
	{
		Point newp(createPoint());
		std::cout << (std::boolalpha) << curr + newp << '\n';
	}
	case 5:
	{
		Line newl(createLine());
		std::cout << (std::boolalpha) << curr.operator||(newl) << '\n';
		break;
	}
	case 6:
	{
		Line newl(createLine());
		std::cout << (std::boolalpha) << curr.operator==(newl) << '\n';
		break;
	}
	case 7:
	{
		Line newl(createLine());
		std::cout << (std::boolalpha) << curr.operator!=(newl) << '\n';
		break;
	}
	case 8:
	{
		Line newl(createLine());
		std::cout << (std::boolalpha) << curr.operator|(newl) << '\n';
		break;
	}
	default:
		break;
	}
}

Segment createSegment()
{
	std::cout << "Creating Segment..." << '\n';
	Point first(createPoint()), secound(createPoint());
	return Segment(first, secound);
}

void segmentOperations(Segment& curr)
{
	unsigned opt;
	std::cout << "Avalable Segment operations: \n"
		<< "1. Get length\n"
		<< "2. Get middle Point\n"
		<< "3. Check if Point lies on Segment\n";
	std::cin.ignore();
	std::cin >> opt;
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
		Point p(createPoint());
		std::cout << (std::boolalpha) << curr.operator==(p) << '\n';
		break;
	}
	default:
		break;
	}
}

Triangle createTriangle()
{
	try
	{
		std::cout << "Creating Triangle...\n";
		Point p1(createPoint()), p2(createPoint()), p3(createPoint());
		Triangle t(p1, p2, p3);
		return t;
	}
	catch (const EqualPointException& ex)
	{
		std::cout << ex.what();
	}
}

void triangleOperations(Triangle& curr)
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
	std::cin.ignore();
	std::cin >> opt;
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
		Point p(createPoint());
		std::cout << (std::boolalpha) << curr.operator<(p) << '\n';
		break;
	}
	case 6:
	{
		Point p(createPoint());
		std::cout << (std::boolalpha) << curr.operator>(p) << '\n';
		break;
	}
	case 7:
	{
		Point p(createPoint());
		std::cout << (std::boolalpha) << curr.operator==(p) << '\n';
		break;
	}
	default:
		break;
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
