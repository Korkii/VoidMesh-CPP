#include <iostream>
#include <cmath>
#include "Calculator.h"

enum Calculator::error_code {
	INVALID_OPERATOR,
	DIVISION_BY_ZERO,
};


/*
Handles errors

@param errorCode The error code to take care of
*/
void Calculator::handleError(error_code errorCode) {
	switch (errorCode) {
	case error_code::INVALID_OPERATOR:
		std::cout << "Invalid operator" << std::endl;
		break;
	case error_code::DIVISION_BY_ZERO:
		std::cout << "Division by zero" << std::endl;
		break;
	default:
		std::cout << "Invalid errorcode" << std::endl;
	}
}

double Calculator::add(double num1, double num2) {
	return num1 + num2;
}


double Calculator::subtract(double num1, double num2) {
	return num1 - num2;
}


double Calculator::divide(double num1, double num2) {
	//if (num2 == 0)
	//	throw error_code::DIVISION_BY_ZERO;
	return num1 / num2;
}


double Calculator::multiply(double num1, double num2) {
	return num1 * num2;
}


double Calculator::calculate(double num1, char op, double num2) {
	try {
		switch (op) {
		case '+':
			return Calculator::add(num1, num2);
			break;
		case '-':
			return Calculator::subtract(num1, num2);
			break;
		case '/':
			return Calculator::divide(num1, num2);
			break;
		case '*':
			return Calculator::multiply(num1, num2);
			break;
		default:
			throw error_code::INVALID_OPERATOR;
		}
	}
	catch (error_code errorCode){
		handleError(errorCode);
		return errorCode;
	}
}