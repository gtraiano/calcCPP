#ifndef CALCULATOR_H_
#define CALCULATOR_H_

#include <queue>
#include <regex>
#include <string>
#include <cmath>
#include <iostream>

#include "DivisionByZero.h"

class Calculator {

private:
	/* store operands and operators */
	std::queue<double> operands;
	std::queue<std::string> operators;

	/* regular expressions for operands and operators */
	const std::regex operatorsRegex;
	const std::regex operandsRegex;
	//const std::string operatorsRegexString = "[+*/^]|-(?!\\d)|mod";
	//const std::string operandsRegexString = "[-]?\\d+\\.?\\d*";

	/* regular expression for acceptable input (ref: https://stackoverflow.com/questions/24234265/how-to-use-regular-expression-for-calculator-input-with-javascript) */
	const std::regex validInput;
	//const std::string commands = "store|recall|clear|help";
	//const std::string validInputString = "^\\s*([-]?\\d+\\.?\\d*)(?:\\s*([+*/^]|-(?!\\d)|mod)\\s*([-]?\\d+\\.?\\d*)\\s*)+$|store|recall|clear|help";

	/* regular expression matches iterators */
	std::sregex_iterator it;
	std::sregex_iterator it_end;

	/* store intermediate calculations result */
	double calc_result = 0.0f;
	double calc_memory = 0.0f;

	/* extract operators and operands from an expression */
	void extractOperators(std::string const&);
	void extractOperands(std::string const&);

public:
	Calculator();
	double calculate(std::string const&) throw(DivisionByZero);
	const bool isValidInput(std::string const&);
	void store();
	double recall();
	void clear();
};

#endif /* CALCULATOR_H_ */
