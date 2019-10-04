#include "computeexception.h"

using namespace Compute::Exceptions;

ComputeException::ComputeException(const char* message) :
    message{message}
{ }

ComputeException::ComputeException(const std::string& message) :
    message{message}
{ }

const char* ComputeException::what() const throw()
{
    return message.c_str();
}
