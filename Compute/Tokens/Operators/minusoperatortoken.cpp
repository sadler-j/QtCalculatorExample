#include "minusoperatortoken.h"

#include "Exceptions/computeexception.h"

using namespace Compute;
using namespace Compute::Exceptions;
using namespace Compute::Tokens;
using namespace Compute::Tokens::Operators;

void MinusOperatorToken::Operate(std::stack<std::shared_ptr<ValueToken>> &valueStack,
                                 const EvaluationSettings& settings) const
{
    if (valueStack.size() < 2)
        throw ComputeException("Insufficient number of arguments for subtraction");

    long double b {PopValue(valueStack)};
    long double a {PopValue(valueStack)};

    valueStack.push(ValueTokenPtr(new ValueToken(a - b)));
}

int MinusOperatorToken::Precedence() const
{
    return 2;
}

bool MinusOperatorToken::RightAssociative() const
{
    return false;
}
