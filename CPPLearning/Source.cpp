#include <iostream>
#include <cmath>

const int MULTIPLICATION_TABLE_SIZE = 11;
const int STARTING_NUM = 1;
const int ALLIGNMENT_OFFSET = 1;
const int ALLIGNMENT_MULTILPLIER = 10;


/*
Prints the multiplication table array
*/
void printMultiplicationTable() {
	double max_identation = std::floor(std::log10((MULTIPLICATION_TABLE_SIZE * MULTIPLICATION_TABLE_SIZE)));
	for (int i = STARTING_NUM; i < MULTIPLICATION_TABLE_SIZE + STARTING_NUM; i++) {
		for (int j = STARTING_NUM; j < MULTIPLICATION_TABLE_SIZE + STARTING_NUM; j++) {
			std::cout << i * j;

			// Taking care of the allignmment, we go 10, 100, 1000, ... until it's at the max allignment + 1
			for (int spaces_counter = i*j; spaces_counter < std::pow(10, max_identation + ALLIGNMENT_OFFSET); spaces_counter *= ALLIGNMENT_MULTILPLIER)
				std::cout << " ";
		}
		std::cout << std::endl;
	}
}

int main()
{
	printMultiplicationTable();
}