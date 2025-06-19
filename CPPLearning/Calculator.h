#pragma once

#include "Exception.h"
#include <string>

class Calculator {
public:
	/*
	Calculates two numbers and operator

	@param num1 first number to add
	@param op character operation to do
	@param num2 second number to add
	@return result of operation
	*/
	static double calculate(double, char op, double);

	class DivisionByZeroException : public Exception {
	public:
		DivisionByZeroException();
	};

	class InvalidOperatorException : public Exception {
	public:
		InvalidOperatorException();
	};

private:
	enum error_code;

	/*
	Handles errors

	@param errorCode The error code of the error
	*/
		
	static void handleError(error_code errorCode);
	/*
	Adds two numbers

	@param num1 first number to add
	@param num2 second number to add
	@return result of addition
	*/
	static double add(double num1, double num2);


	/*
	Subtract two numbers

	@param num1 first number to add
	@param num2 second number to add
	@return result of subtraction
	*/
	static double subtract(double, double);
	
	
	/*
	Multiplies two numbers

	@param num1 first number to add
	@param num2 second number to add
	@return result of multiplication
	*/
	static double multiply(double, double);
	
	/*
	Divides two numbers

	Divides the first argument by the second argument, if the second argument is 0, will throw error_code::DIVISION_BY_ZERO

	@param num1 first number to add
	@param num2 second number to add
	@return result of addition
	*/
	static double divide(double, double);
};