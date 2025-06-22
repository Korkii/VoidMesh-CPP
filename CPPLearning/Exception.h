#pragma once

#include <string>


class Exception
{
public:
	Exception(std::string type);

	std::string getExceptionType();

private:
	std::string exception_type;
};
