#include <iostream>
#include <cmath>


const int MIN_PRIME = 2;

enum error_code {
	SUCCESS,
	BAD_INPUT,
};


/*
Handles errors

@param errorCode The error code to take care of
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


/*
Checks if a number is prime and returns the answer

@param num Integer to check if prime
@return boolean reprenseting prime state of the number
*/
bool isPrime(int num) {
	if (num < MIN_PRIME)
		return false;

	for (int i = 2; i <= std::floor(std::sqrt(num)); i++) {
		if (num % i == 0)
			return false;
	}
	return true;
}


int main()
{
	try {
		int number_input = 0;

		std::cout << "Enter a number to check if prime: ";

		if (!(std::cin >> number_input))
			throw error_code::BAD_INPUT;

		if (isPrime(number_input)) {
			std::cout << "Number is prime" << std::endl;
		} else {
			std::cout << "Number is not prime" << std::endl;
		}
	}
	catch (error_code errorCode) {
		handleError(errorCode);
		return errorCode;
	}
	return error_code::SUCCESS;
}