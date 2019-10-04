#include "timesoperatortoken.h"

#include "Exceptions/computeexception.h"

using namespace Compute;
using namespace Compute::Exceptions;
using namespace Compute::Tokens;
using namespace Compute::Tokens::Operators;

TimesOperatorToken::TimesOperatorToken()
{ }

void TimesOperatorToken::Operate(std::stack<std::shared_ptr<ValueToken>>& valueStack,
                                 const EvaluationSettings& settings) const
{
    if (valueStack.size() < 2)
        throw ComputeException("Insufficient number of arguments for multiplication");

    long double b {PopValue(valueStack)};
    long double a {PopValue(valueStack)};

    valueStack.push(ValueTokenPtr(new ValueToken(a * b)));
}

int TimesOperatorToken::Precedence() const
{
    return 3;
}

bool TimesOperatorToken::RightAssociative() const
{
    return false;
}
