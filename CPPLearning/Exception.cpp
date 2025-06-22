#include "Exception.h"
#include <string>

Exception::Exception(std::string type) {
	exception_type = type;
}

std::string Exception::getExceptionType() {
	return exception_type;
}