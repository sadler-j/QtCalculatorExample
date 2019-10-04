#include "maxfunctiontoken.h"

#include <limits>

#include "Exceptions/computeexception.h"

using namespace Compute;
using namespace Compute::Exceptions;
using namespace Compute::Tokens;
using namespace Compute::Tokens::Functions;

void MaxFunctionToken::Operate(std::stack<ValueTokenPtr>& valueTokens,
                               const EvaluationSettings& settings) const
{
    if (GetNumberOfArguments() < 1)
        throw ComputeException("Invalid number of arguments for max function");

    long double max {std::numeric_limits<double>::lowest()};
    for (size_t i{0}; i < GetNumberOfArguments(); i++)
    {
        long double value {PopValue(valueTokens)};
        if (value > max)
            max = value;
    }

    valueTokens.push(ValueTokenPtr(new ValueToken(max)));
}
