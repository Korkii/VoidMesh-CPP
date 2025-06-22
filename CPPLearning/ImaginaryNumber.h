#pragma once
#include <ostream>
class ImaginaryNumber
{
public:
    ImaginaryNumber()
        : m_realComponent(0.0), m_imagComponent(0.0)
    {}

    ImaginaryNumber(double realComponent, double imagComponent) : m_realComponent{ realComponent }, m_imagComponent{ imagComponent } {}


    /*
    Overrides the addition operation

    @param other Another ImaginaryNumber object to add
    @return the result of the operation
    */
    ImaginaryNumber& operator+(const ImaginaryNumber& other);

    /*
    Overrides the subtractions operation

    @param other Another ImaginaryNumber object to add
    @return the result of the operation
    */
    ImaginaryNumber& operator-(const ImaginaryNumber& other);

    /*
    Overrides the multiplication operation

    @param other Another ImaginaryNumber object to add
    @return the result of the operation
    */
    ImaginaryNumber& operator*(const ImaginaryNumber& other);

    /*
    Overrides the equal operation

    @param other Another ImaginaryNumber object to add
    @return the result of the operation
    */
    bool operator==(const ImaginaryNumber& other);

    /*
    A getter for the real component of the imaginary number
    
    @return The real component of the imaginary number
    */
    const double getRealComponent() const { return this->m_realComponent; }
    
    /*
    A getter for the imaginary component of the imaginary number

    @return The imaginary component of the imaginary number
    */
    const  double getImagComponent() const { return this->m_imagComponent; }

    /*
    Overrides the << operator
    
    @param imaginaryNumber The imaginary number to print
    @param out The stream to put the data into
    @return the stream to output
    */
    friend std::ostream& operator<< (std::ostream& out, const ImaginaryNumber& imaginaryNumber);

private:
     double m_realComponent;
     double m_imagComponent;
};
