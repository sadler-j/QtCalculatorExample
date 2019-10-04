#ifndef COMPUTEEXCEPTION_H
#define COMPUTEEXCEPTION_H

#include <exception>
#include <string>

namespace Compute
{
namespace Exceptions
{
class ComputeException : public std::exception
{
public:
    explicit ComputeException(const char* message);
    explicit ComputeException(const std::string& message);

    virtual ~ComputeException() throw() = default;

    virtual const char* what() const throw ();

private:
    std::string message;
};
}
}

#endif // COMPUTEEXCEPTION_H
