#include <iostream>
#include <cmath>


const int MINIMUM_POSITIVE_NUM = 0;

enum error_code {
	SUCCESS,
	INPUT_FAIL,
	NEGATIVE_INPUT,
};


/*
Handles all error types

@param errorCode Error code to take care of
*/
void handle_errors(error_code errorCode) {
	switch (errorCode) {
	case error_code::INPUT_FAIL:
		std::cout << "Bad input" << std::endl;
		break;
	case error_code::NEGATIVE_INPUT:
		std::cout << "Program cannot process negative numbers" << std::endl;
		break;
	default:
		std::cout << "Invalid errorcode" << std::endl;
	}
}


/*
Asks the user for a number, and returns it's square root.

@return square root of the user input
*/
double my_sqrt() {
	std::cout << "Please type a number: ";
	int input_number = MINIMUM_POSITIVE_NUM;

	if (!(std::cin >> input_number)) {
		throw error_code::INPUT_FAIL;
	}

	if (input_number < MINIMUM_POSITIVE_NUM) {
		throw error_code::NEGATIVE_INPUT;
	}
	return std::sqrt(input_number);
}


int main()
{
	try {
		std::cout << my_sqrt() << std::endl;
	}
	catch (error_code errorCode) {
		handle_errors(errorCode);
		return errorCode;
	}

	return error_code::SUCCESS;
}