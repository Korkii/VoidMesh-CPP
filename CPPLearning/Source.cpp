#include <iostream>

#define MULTIPLICATION_TABLE_SIZE 11


void print_table(int table[MULTIPLICATION_TABLE_SIZE][MULTIPLICATION_TABLE_SIZE], int width, int height) {
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			std::cout << table[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

int main()
{
	int multiplication_table[MULTIPLICATION_TABLE_SIZE][MULTIPLICATION_TABLE_SIZE] = { 0 };

	for (int i = 0; i < MULTIPLICATION_TABLE_SIZE; i++) {
		for (int j = 0; j < MULTIPLICATION_TABLE_SIZE; j++) {
			multiplication_table[i][j] = i * j;
		}
	}

	print_table(multiplication_table, MULTIPLICATION_TABLE_SIZE, MULTIPLICATION_TABLE_SIZE);
}

