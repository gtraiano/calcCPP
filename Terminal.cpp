#include "Calculator.h"
#include <iostream>
#include <limits.h>
#include <algorithm>
#include <cctype>

namespace util {
bool toLowerCase(std::string& input) {
	std::transform(input.begin(), input.end(), input.begin(), [](unsigned char c){ return std::tolower(c); });
	return input.length(); // just to be used in logical expressions
}
}

int main(void) {
	std::string input;
	Calculator calc;

	while(
			(std::cout << "> ") && (std::cin >> input) 	// input expression or command
			&& util::toLowerCase(input) 				// convert to lower case
			&& (input != "exit") 						// check for exit command
	) {
		if(!calc.isValidInput(input)) {
			std::cout << "Invalid input" << std::endl;
		}

		else {
			try {
				if(input == "store") {
					calc.store();
					std::cout << "Stored " << calc.recall() << std::endl;
				}

				else if(input == "recall") {
					std::cout << "Recalled "<< calc.recall() << std::endl;
					std::cout << "> " << calc.recall(); std::cin >> input;

					input = std::to_string(calc.recall()) + input;
					//std::cout << input << " [DEBUG]" << std::endl;
					if(!calc.isValidInput(input)) {
						std::cout << "Invalid input" << std::endl;
						continue;
					}
					std::cout << input << " = " << calc.calculate(input) << std::endl;
				}

				else if(input == "clear") {
					calc.clear();
					std::cout << "Cleared" << std::endl;
				}

				else if(input == "help") {
					std::cout << "Available operations\n+ : Addition\n- : Subtraction\n* : Multiplication\
							\n/ : Division\n% : Modulo\n^ : Power" << std::endl;
				}

				else {
					std::cout << input << " = " << calc.calculate(input) << std::endl;
					//calc.calculate(input);
				}
			}
			catch(std::exception const& e) {
				std::cout << e.what() << std::endl;
			}
		}
	}
	return EXIT_SUCCESS;
}
