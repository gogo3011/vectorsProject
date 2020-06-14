#ifndef H_ELEMENT_H
#define H_ELEMENT_H
#include <ostream>
#include <fstream>

class Element {
public:
	virtual std::ostream& ins(std::ostream& out) const = 0;
	virtual std::ofstream& ins(std::ofstream& fstream) const = 0;
};

std::ostream& operator<<(std::ostream& out, const Element& rhs);
std::ofstream& operator<<(std::ofstream& out, const Element& rhs);
#endif // !H_ELEMENT_H
