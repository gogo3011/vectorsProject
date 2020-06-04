#ifndef H_EQ_POINT_H
#define H_EQ_POINT_H
#include <exception>

class EqualPointException :public std::exception {
public:
	virtual const char* what() const throw();
};
#endif // !H_EQ_POINT_H