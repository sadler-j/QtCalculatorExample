#ifndef SINFUNCTIONTOKEN_H
#define SINFUNCTIONTOKEN_H

#include "Tokens/Functions/functiontoken.h"

namespace Compute
{
namespace Tokens
{
namespace Functions
{
namespace Trigonometric
{
class SinFunctionToken : public FunctionToken
{
public:
    void Operate(std::stack<ValueTokenPtr>& valueTokens,
                 const EvaluationSettings& settings) const override;
};
}
}
}
}

#endif // SINFUNCTIONTOKEN_H
