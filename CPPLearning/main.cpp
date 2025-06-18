#include <iostream>
#include "Calculator.h"

enum error_code {
	SUCCESS,
	BAD_INPUT,
};

/*
Handles all error types

@param errorCode Error code to take care of
*/
void handleError(error_code errorCode) {
	switch (errorCode) {
	case error_code::BAD_INPUT:
		std::cout << "Bad input" << std::endl;
		break;
	default:
		std::cout << "Invalid errorcode" << std::endl;
	}
}

int main() {
	try {
		int num1 = 0;
		int num2 = 0;
		char op = 'X';

		std::cout << "Please type a number: " << std::endl;
		if (!(std::cin >> num1)) {
			throw error_code::BAD_INPUT;
		}

		std::cout << "Please type a number: " << std::endl;
		if (!(std::cin >> num2)) {
			throw error_code::BAD_INPUT;
		}

		std::cout << "Please type an operator [+,-,*,/]: " << std::endl;
		if (!(std::cin >> op)) {
			throw error_code::BAD_INPUT;
		}

		Calculator calc;
		std::cout << calc.calculate(num1, op, num2) << std::endl;
	}
	catch (error_code errorCode) {
		handleError(errorCode);
		return errorCode;
	}
}