#include "Calculator.h"

Calculator::Calculator()
	: operatorsRegex("[%*/+^-]|mod")
	, operandsRegex("\\d+\\.?\\d*")
	, validInput("^\\s*(\\d+\\.?\\d*)(?:\\s*([-%+^*/]|mod)\\s*(\\d+\\.?\\d*)\\s*)+$|store|recall|clear|help") {
}

void Calculator::extractOperators(std::string const& input) {
	it = std::sregex_iterator(input.begin(), input.end(), operatorsRegex);
	while(it != it_end) {
		operators.push(it->str());
		++it;
	}
}

void Calculator::extractOperands(std::string const& input) {
	it = std::sregex_iterator(input.begin(), input.end(), operandsRegex);
	while(it != it_end) {
		operands.push(std::stod(it->str()));
		++it;
	}
}

double Calculator::calculate(std::string const& input) throw(DivisionByZero) {
	extractOperators(input);
	extractOperands(input);

	calc_result = operands.front();
	operands.pop();

	//std::cout << calc_result << std::endl;

	while(!operators.empty()) {
		std::string op = operators.front();
		operators.pop();

		double b = operands.front();
		operands.pop();

		if(op == "+")
			calc_result += b;
		else if(op == "-")
			calc_result -= b;
		else if(op == "*")
			calc_result *= b;
		else if(op == "/")
			calc_result = b ? calc_result/b : throw DivisionByZero();
		else if(op == "^")
			calc_result = std::pow(calc_result, b);
		else if(op == "%" || op == "mod")
			calc_result = std::fmod(calc_result, b);

		//std::cout << op << std::endl << b << std::endl;
	}

	//std::cout << "=" << calc_result << std::endl;

	return calc_result;
}


const bool Calculator::isValidInput(std::string const& input) {
	return !std::regex_match(input, validInput) ? false : true;
}

void Calculator::store() {
	calc_memory = calc_result;
}

double Calculator::recall() {
	return calc_memory;
}

void Calculator::clear() {
	calc_memory = 0;
}
