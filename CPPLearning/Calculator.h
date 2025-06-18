#pragma once

class Calculator {
public:
	Calculator();
	
	// Basicl Functionality
	double add(double num1, double num2);
	double subtract(double, double);
	double multiply(double, double);
	double divide(double, double);
	double calculate(double, char op, double);

	// Error Handling
	enum error_code;
	void handleError(error_code errorCode);
};