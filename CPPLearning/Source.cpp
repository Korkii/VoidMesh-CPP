#include <iostream>


int main()
{
	std::cout << "Please type a number: ";
	int input_number = 0;

	std::cin >> input_number;

	if (input_number < 0) {
		std::cout << "Program cannot process negative numbers" << std::endl;
		return 1;
	}
	std::cout << std::sqrt(input_number) << std::endl;
	return 0;
}