#include "ImaginaryNumber.h"
#include <iostream>


ImaginaryNumber& ImaginaryNumber::operator+(const ImaginaryNumber& other) {
    return ImaginaryNumber((m_realComponent + other.m_realComponent), (m_imagComponent + other.m_imagComponent));
}

ImaginaryNumber& ImaginaryNumber::operator-(const ImaginaryNumber& other) {
    return ImaginaryNumber((this->m_realComponent - other.m_realComponent), (this->m_imagComponent - other.m_imagComponent));
}

ImaginaryNumber& ImaginaryNumber::operator*(const ImaginaryNumber& other) {
    return ImaginaryNumber((this->m_realComponent * other.m_realComponent), (this->m_imagComponent * other.m_imagComponent));
}

bool ImaginaryNumber::operator==(const ImaginaryNumber& other) {
    return (this->m_realComponent == other.m_realComponent) && (this->m_imagComponent == other.m_imagComponent);
}

std::ostream& operator<<(std::ostream& out, const ImaginaryNumber& imaginaryNumber)
{
    out << "(" << imaginaryNumber.m_realComponent << " + " << imaginaryNumber.m_imagComponent << "i)" << std::endl;

    return out;
}
