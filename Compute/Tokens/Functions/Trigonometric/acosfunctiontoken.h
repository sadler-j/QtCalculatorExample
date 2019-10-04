#ifndef ACOSFUNCTIONTOKEN_H
#define ACOSFUNCTIONTOKEN_H

#include "Tokens/Functions/functiontoken.h"

namespace Compute
{
namespace Tokens
{
namespace Functions
{
namespace Trigonometric
{
class ACosFunctionToken : public FunctionToken
{
public:
    void Operate(std::stack<ValueTokenPtr>& valueTokens,
                 const EvaluationSettings& settings) const override;
};
}
}
}
}

#endif // ACOSFUNCTIONTOKEN_H
