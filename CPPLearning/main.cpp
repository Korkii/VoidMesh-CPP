#include <iostream>
#include "Exception.h"
#include "Calculator.h"

enum error_code {
	SUCCESS,
	BAD_INPUT,
	CALC_ERROR,
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


int getInt() {
	int num;
	std::cout << "Please type a number: " << std::endl;
	if (!(std::cin >> num)) {
		throw error_code::BAD_INPUT;
	}

	return num;
}



int getOperator() {
	char op = 'X';
	std::cout << "Please type an operator [+,-,*,/]: " << std::endl;
	if (!(std::cin >> op)) {
		throw error_code::BAD_INPUT;
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
	catch (error_code errorCode) {
		handleError(errorCode);
		return errorCode;
	}
	catch (Exception exception) {
		return error_code::CALC_ERROR;
	}
}