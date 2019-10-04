#include "cosfunctiontoken.h"

#include <cmath>

#include "mathtools.h"
#include "Exceptions/computeexception.h"

using namespace Compute;
using namespace Compute::Exceptions;
using namespace Compute::Tokens;
using namespace Compute::Tokens::Functions;
using namespace Compute::Tokens::Functions::Trigonometric;

void CosFunctionToken::Operate(std::stack<std::shared_ptr<ValueToken>>& valueTokens,
                               const EvaluationSettings& settings) const
{
    if (GetNumberOfArguments() != 1)
        throw ComputeException("Invalid number of arguments for cos function");

    long double angle {PopValue(valueTokens)};

    if (!settings.IsRadians())
        angle = MathTools::DegreesToRadians(angle);

    valueTokens.push(ValueTokenPtr(new ValueToken(std::cosl(angle))));
}
