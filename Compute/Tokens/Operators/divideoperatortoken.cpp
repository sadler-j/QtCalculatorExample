#include "divideoperatortoken.h"

#include "Exceptions/computeexception.h"

using namespace Compute;
using namespace Compute::Exceptions;
using namespace Compute::Tokens;
using namespace Compute::Tokens::Operators;

DivideOperatorToken::DivideOperatorToken()
{ }

void DivideOperatorToken::Operate(std::stack<ValueTokenPtr>& valueStack,
                                  const EvaluationSettings& settings) const
{
    if (valueStack.size() < 2)
        throw ComputeException("Insufficient number of arguments for division");

    long double div {PopValue(valueStack)};
    long double num {PopValue(valueStack)};

    valueStack.push(ValueTokenPtr(new ValueToken(num / div)));
}

int DivideOperatorToken::Precedence() const
{
    return 3;
}

bool DivideOperatorToken::RightAssociative() const
{
    return false;
}
