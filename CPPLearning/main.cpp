#include <iostream>
#include "Calculator.h"

enum error_code {
	SUCCESS,
	BAD_INPUT,
};


int main() {
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