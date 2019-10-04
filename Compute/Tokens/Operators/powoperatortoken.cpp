#include "powoperatortoken.h"

#include <cmath>

#include "Exceptions/computeexception.h"

using namespace Compute;
using namespace Compute::Exceptions;
using namespace Compute::Tokens;
using namespace Compute::Tokens::Operators;

PowOperatorToken::PowOperatorToken()
{ }

void PowOperatorToken::Operate(std::stack<std::shared_ptr<ValueToken>>& valueStack,
                               const EvaluationSettings& settings) const
{
    if (valueStack.size() < 2)
        throw ComputeException("Insufficient number of arguments for power operation");

    long double b {PopValue(valueStack)};
    long double a {PopValue(valueStack)};

    valueStack.push(ValueTokenPtr(new ValueToken(std::pow(a, b))));
}

int PowOperatorToken::Precedence() const
{
    return 4;
}

bool PowOperatorToken::RightAssociative() const
{
    return true;
}
