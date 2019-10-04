#include "plusoperatortoken.h"

#include "Exceptions/computeexception.h"

using namespace Compute;
using namespace Compute::Exceptions;
using namespace Compute::Tokens;
using namespace Compute::Tokens::Operators;

PlusOperatorToken::PlusOperatorToken()
{ }

void PlusOperatorToken::Operate(std::stack<std::shared_ptr<ValueToken>>& valueStack,
                                const EvaluationSettings& settings) const
{
    if (valueStack.size() < 2)
        throw ComputeException("Insufficient number of arguments for addition");

    long double b {PopValue(valueStack)};
    long double a {PopValue(valueStack)};

    valueStack.push(ValueTokenPtr(new ValueToken(a + b)));
}

int PlusOperatorToken::Precedence() const
{
    return 2;
}

bool PlusOperatorToken::RightAssociative() const
{
    return false;
}
