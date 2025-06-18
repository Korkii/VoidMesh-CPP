#pragma once

class Calculator {
public:
	
	// Basic Functionality

	/*
	Adds two numbers

	@param num1 first number to add
	@param num2 second number to add
	@return result of addition
	*/
	double add(double num1, double num2);


	/*
	Subtract two numbers

	@param num1 first number to add
	@param num2 second number to add
	@return result of subtraction
	*/
	double subtract(double, double);
	
	
	/*
	Multiplies two numbers

	@param num1 first number to add
	@param num2 second number to add
	@return result of multiplication
	*/
	double multiply(double, double);
	
	/*
	Divides two numbers

	@param num1 first number to add
	@param num2 second number to add
	@return result of addition
	*/
	double divide(double, double);
	

	/*
	Calculates two numbers and operator

	@param num1 first number to add
	@param op character operation to do
	@param num2 second number to add
	@return result of operation
	*/
	double calculate(double, char op, double);

	// Error Handling
	enum error_code;

	/*
	Handles errors

	@param errorCode The error code of the error
	*/
	void handleError(error_code errorCode);
};