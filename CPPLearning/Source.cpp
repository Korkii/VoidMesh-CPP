#include <iostream>
#include <cmath>


const int MIN_PRIME = 2;

enum error_code {
	SUCCESS,
	BAD_INPUT,
	NEGATIVE_COUNT,
	NULL_PTR,
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
	case error_code::NULL_PTR:
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
void fill_prime(int num, int* arr) {
	if (arr == nullptr)
		throw error_code::NULL_PTR;

	if (num <= 0)
		throw error_code::NEGATIVE_COUNT;

	int prime_count = 0;

	for (int i = MIN_PRIME; prime_count != num; i += 1) {
		if (i != MIN_PRIME && i % 2 == 0)
			continue;

		if (isPrime(i)) {
			arr[prime_count] = i;
			prime_count++;
		}
	}
}


/*
Get integer input from user

@return the number received from the user
*/
int getInt() {
	int number_input = 0;

	std::cout << "Enter a number to find primes: ";

	if (!(std::cin >> number_input))
		throw error_code::BAD_INPUT;

	if (number_input <= 0) {
		throw error_code::NEGATIVE_COUNT;
	}

	return number_input;
}


/*
Prints a 1d integer array

@param arr Array of integer
@param length Length of array
*/
void printIntegerArray(int *arr, int length) {
	for (int i = 0; i < length; i++) {
		std::cout << arr[i] << " ";
	}
}


int main() {
	int* arr = nullptr;
	try {
		
		int number_input = getInt();

		arr = new int[number_input];
		fill_prime(number_input, arr);

		printIntegerArray(arr, number_input);
		
		
	}
	catch (error_code errorCode) {
		handleError(errorCode);
		return errorCode;
	}

	if (arr != nullptr) {
		delete[] arr;
	}
	return error_code::SUCCESS;
}