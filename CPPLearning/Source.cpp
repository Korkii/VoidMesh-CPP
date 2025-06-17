#include <iostream>
#include <cmath>

const int MULTIPLICATION_TABLE_SIZE = 11;
const int STARTING_NUM = 1;
const int ALLIGNMENT_OFFSET = 1;
const int ALLIGNMENT_MULTILPLIER = 10;


/*
Prints the multiplication table array

@param table The multiplication table to print
*/
void print_multiplication_table(int table[MULTIPLICATION_TABLE_SIZE * MULTIPLICATION_TABLE_SIZE]) {
	double max_identation = std::floor(std::log10((MULTIPLICATION_TABLE_SIZE * MULTIPLICATION_TABLE_SIZE)));
	for (int i = 0; i < MULTIPLICATION_TABLE_SIZE; i++) {
		for (int j = 0; j < MULTIPLICATION_TABLE_SIZE; j++) {
			std::cout << table[i * MULTIPLICATION_TABLE_SIZE + j];

			// Taking care of the allignmment, we go 10, 100, 1000, ... until it's at the max allignment + 1
			for (int spaces = table[i * MULTIPLICATION_TABLE_SIZE + j]; spaces < std::pow(10, max_identation + ALLIGNMENT_OFFSET); spaces *= ALLIGNMENT_MULTILPLIER)
				std::cout << " ";
		}
		std::cout << std::endl;
	}
}

int main()
{
	int multiplication_table[MULTIPLICATION_TABLE_SIZE * MULTIPLICATION_TABLE_SIZE] = { 0 };

	for (int i = STARTING_NUM; i < MULTIPLICATION_TABLE_SIZE + STARTING_NUM; i++) {
		for (int j = STARTING_NUM; j < MULTIPLICATION_TABLE_SIZE + STARTING_NUM; j++) {
			multiplication_table[(i - STARTING_NUM) * MULTIPLICATION_TABLE_SIZE + (j - STARTING_NUM)] = i * j;
		}
	}

	print_multiplication_table(multiplication_table);
}