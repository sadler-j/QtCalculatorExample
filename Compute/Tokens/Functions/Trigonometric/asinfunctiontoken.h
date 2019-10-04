#ifndef ASINFUNCTIONTOKEN_H
#define ASINFUNCTIONTOKEN_H

#include "Tokens/Functions/functiontoken.h"

namespace Compute
{
namespace Tokens
{
namespace Functions
{
namespace Trigonometric
{
class ASinFunctionToken : public FunctionToken
{
public:
    void Operate(std::stack<ValueTokenPtr>& valueTokens,
                 const EvaluationSettings& settings) const override;
};
}
}
}
}

#endif // ASINFUNCTIONTOKEN_H
