#include "atanfunctiontoken.h"

#include <cmath>

#include "mathtools.h"
#include "Exceptions/computeexception.h"

using namespace Compute;
using namespace Compute::Exceptions;
using namespace Compute::Tokens;
using namespace Compute::Tokens::Functions;
using namespace Compute::Tokens::Functions::Trigonometric;

void ATanFunctionToken::Operate(std::stack<std::shared_ptr<ValueToken>>& valueTokens,
                                const EvaluationSettings& settings) const
{
    if (GetNumberOfArguments() != 1)
        throw ComputeException("Invalid number of arguments for atan function");

    long double value {PopValue(valueTokens)};
    long double angle {std::atanl(value)};

    if (!settings.IsRadians())
        angle = MathTools::RadiansToDegrees(angle);

    valueTokens.push(ValueTokenPtr(new ValueToken(angle)));
}
