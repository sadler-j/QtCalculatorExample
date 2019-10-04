#include "absfunctiontoken.h"

#include <cmath>

#include "Exceptions/computeexception.h"

using namespace Compute;
using namespace Compute::Exceptions;
using namespace Compute::Tokens;
using namespace Compute::Tokens::Functions;

void AbsFunctionToken::Operate(std::stack<ValueTokenPtr>& valueTokens,
                               const EvaluationSettings& settings) const
{
    if (GetNumberOfArguments() != 1)
        throw ComputeException("Invalid number of arguments for absolute value function");

    long double value {PopValue(valueTokens)};

    valueTokens.push(ValueTokenPtr(new ValueToken(std::fabsl(value))));
}
