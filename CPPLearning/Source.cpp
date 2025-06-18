#include <iostream>
#include <cmath>


const int MIN_PRIME = 2;
const int MIN_ODD_PRIME = 3;
const int PARITY_OFFSET = 2;

enum error_code {
	SUCCESS,
	BAD_INPUT,
	NEGATIVE_COUNT,
	NULL_PTR_ACCESS,
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
	case error_code::NEGATIVE_COUNT:
		std::cout << "Negative or zero count" << std::endl;
		break;
	case error_code::NULL_PTR_ACCESS:
		std::cout << "Null pointer access" << std::endl;
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


/*
Fills an array arr in num primes.

@param num Integer representing the number of prime numbers to find
@param arr Pointer to an array to fill in prime numbers
*/
void fill_prime(int num, int** arr) {
	if (num <= 0)
		throw error_code::NEGATIVE_COUNT;

	int prime_count = 0;

	for (int i = 2; prime_count != num; i += PARITY_OFFSET) {
		if (i == 2) {
			if (!((*arr)[prime_count]))
				throw error_code::NULL_PTR_ACCESS;
			(*arr)[prime_count] = i;
			prime_count++;
			i++;
			continue;
		}
		if (isPrime(i)) {
			if (!((*arr)[prime_count]))
				throw error_code::NULL_PTR_ACCESS;
			(*arr)[prime_count] = i;
			prime_count++;
		}
	}
}


int main()
{
	try {
		int number_input = 0;

		std::cout << "Enter a number to find primes: ";

		if (!(std::cin >> number_input))
			throw error_code::BAD_INPUT;

		if (number_input <= 0) {
			throw error_code::NEGATIVE_COUNT;
		}

		int* arr = new int[number_input];
		fill_prime(number_input, &arr);

		for (int i = 0; i < number_input; i++) {
			std::cout << arr[i] << " ";
		}
		
		free(arr);
	}
	catch (error_code errorCode) {
		handleError(errorCode);
		return errorCode;
	}

	return error_code::SUCCESS;
}