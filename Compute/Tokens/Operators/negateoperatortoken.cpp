#include "negateoperatortoken.h"

#include "Exceptions/computeexception.h"

using namespace Compute;
using namespace Compute::Exceptions;
using namespace Compute::Tokens;
using namespace Compute::Tokens::Operators;

void NegateOperatorToken::Operate(std::stack<std::shared_ptr<ValueToken>> &valueStack,
                                  const EvaluationSettings& settings) const
{
    if (valueStack.size() < 1)
        throw ComputeException("Insufficient number of arguments for negate operation");

    long double value {PopValue(valueStack)};

    valueStack.push(ValueTokenPtr(new ValueToken(-value)));
}

int NegateOperatorToken::Precedence() const
{
    return 4;
}

bool NegateOperatorToken::RightAssociative() const
{
    return true;
}
