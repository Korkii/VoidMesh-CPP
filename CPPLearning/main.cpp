#include <iostream>
#include "ImaginaryNumber.h"


int main() {
	ImaginaryNumber x = ImaginaryNumber(0,0);
	ImaginaryNumber y = ImaginaryNumber(5, 4);
	ImaginaryNumber z = x + y;
	std::cout << z.getRealComponent() << "," << z.getImagComponent() << std::endl;
	std::cout << z << std::endl;

	if (x == y) {
		std::cout << "wrong evaluation" << std::endl;
	}
	else {
		std::cout << "good evaluation" << std::endl;
	}
	return 0;
}