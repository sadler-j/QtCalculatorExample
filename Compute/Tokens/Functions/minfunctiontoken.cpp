#include "minfunctiontoken.h"

#include <limits>

#include "Exceptions/computeexception.h"

using namespace Compute;
using namespace Compute::Exceptions;
using namespace Compute::Tokens;
using namespace Compute::Tokens::Functions;

void MinFunctionToken::Operate(std::stack<std::shared_ptr<ValueToken>>& valueTokens,
                               const EvaluationSettings& settings) const
{
    if (GetNumberOfArguments() < 1)
        throw ComputeException("Invalid number of arguments for min function");

    long double min {std::numeric_limits<long double>::max()};
    for (size_t i{0}; i < GetNumberOfArguments(); i++)
    {
        double value = PopValue(valueTokens);
        if (value < min)
            min = value;
    }

    valueTokens.push(ValueTokenPtr(new ValueToken(min)));
}
