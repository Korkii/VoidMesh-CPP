#include <iostream>
#include <cmath>
#include "Calculator.h"


Calculator::DivisionByZeroException::DivisionByZeroException() : MyException{"Division By Zero"} {};
Calculator::InvalidOperatorException::InvalidOperatorException() : MyException{"Invalid Operator"} {};


double Calculator::add(double num1, double num2) {
	return num1 + num2;
}

double Calculator::subtract(double num1, double num2) {
	return num1 - num2;
}

double Calculator::divide(double num1, double num2) {
	if (num2 == 0) {
		throw DivisionByZeroException();
	}
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
			throw InvalidOperatorException();
		}
	}
	catch (const MyException& exception) {
		throw exception;
	}
}