#pragma once

class ComplexNum {
public:
	ComplexNum();
	ComplexNum(int a, int b);
	
	void setReal(int a);
	void setImaginary(int b);

	ComplexNum operator+(const ComplexNum& other);
	ComplexNum operator*(const ComplexNum& other);
	ComplexNum operator-(const ComplexNum& other);
	ComplexNum operator==(const ComplexNum& other);


	int real;
	int complex;

};