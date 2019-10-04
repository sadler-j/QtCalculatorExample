#include "asinfunctiontoken.h"

#include <cmath>

#include "mathtools.h"
#include "Exceptions/computeexception.h"

using namespace Compute;
using namespace Compute::Exceptions;
using namespace Compute::Tokens;
using namespace Compute::Tokens::Functions;
using namespace Compute::Tokens::Functions::Trigonometric;

void ASinFunctionToken::Operate(std::stack<ValueTokenPtr>& valueTokens,
                                const EvaluationSettings& settings) const
{
    if (GetNumberOfArguments() != 1)
        throw ComputeException("Invalid number of arguments for asin function");

    long double value {PopValue((valueTokens))};
    long double angle {std::asinl(value)};

    if (!settings.IsRadians())
        angle = MathTools::RadiansToDegrees(angle);

    valueTokens.push(ValueTokenPtr(new ValueToken(angle)));
}
