#ifndef H_VECTOR_LEN_EXC_H
#define H_VECTOR_LEN_EXC_H
#include <exception>

class VectorLengthException :public std::exception {
	virtual const char* what() const throw();
};
#endif // !H_VECTOR_LEN_EXC_H