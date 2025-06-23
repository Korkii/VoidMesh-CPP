#include <iostream>

#include "Calculator.h"

enum error_code {
	SUCCESS,
	ERROR
};

class BadInputException : public MyException {
public:
	BadInputException() : MyException{ "Bad input" } {};
};


int getInt() {
	int num;
	std::cout << "Please type a number: " << std::endl;
	if (!(std::cin >> num)) {
		throw BadInputException();
	}

	return num;
}



int getOperator() {
	char op = 'X';
	std::cout << "Please type an operator [+,-,*,/]: " << std::endl;
	if (!(std::cin >> op)) {
		throw BadInputException();
	}

	return op;
}


int main() {
	try {
		int num1 = getInt();
		int num2 = getInt();
		char op = getOperator();

		std::cout << Calculator::calculate(num1, op, num2) << std::endl;
	}
	catch (MyException exception) {
		std::cerr << "An exception occurred (" << exception.getError() << ")\n";
		return error_code::ERROR;
	}
	return error_code::SUCCESS;
}