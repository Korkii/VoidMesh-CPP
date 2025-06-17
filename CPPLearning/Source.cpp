#include <iostream>

#define MINIMUM_POSITIVE_NUM 0


enum class error_code {
	SUCCESS,
	INPUT_FAIL,
	NEGATIVE_INPUT,
};


/*
Throws an input faid error code, used for when stdin isn't working
*/
void inputFailThrower() {
	throw error_code::INPUT_FAIL;
}


/*
Throws a negative input error code, used for trying to apply sqrt on negative numbers
*/
void negativeInputThrower() {
	throw error_code::NEGATIVE_INPUT;
}


/*
Handles all error types

@param errorCode Error code to take care of
*/
void handle_errors(error_code errorCode) {
	if (errorCode == error_code::INPUT_FAIL)
		std::cout << "Stdin not working properly" << std::endl;
	else if (errorCode == error_code::NEGATIVE_INPUT)
		std::cout << "Program cannot process negative numbers" << std::endl;
}


int main()
{
	try {
		std::cout << "Please type a number: ";
		int input_number = MINIMUM_POSITIVE_NUM;

		if (!std::cin) {
			inputFailThrower();
		}

		std::cin >> input_number;

		if (input_number < MINIMUM_POSITIVE_NUM) {
			negativeInputThrower();
		}
		std::cout << std::sqrt(input_number) << std::endl;
	}
	catch (error_code errorCode) {
		handle_errors(errorCode);
	}

	return 0;
}