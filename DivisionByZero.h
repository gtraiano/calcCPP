#ifndef DIVISIONBYZERO_H_
#define DIVISIONBYZERO_H_

#include <exception>

class DivisionByZero : public std::exception {
	virtual const char* what() const throw() {
		return "Division by zero!";
	}
};

#endif /* DIVISIONBYZERO_H_ */

