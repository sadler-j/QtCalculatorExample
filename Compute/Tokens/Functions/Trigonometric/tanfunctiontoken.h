#ifndef TANFUNCTIONTOKEN_H
#define TANFUNCTIONTOKEN_H

#include "Tokens/Functions/functiontoken.h"

namespace Compute
{
namespace Tokens
{
namespace Functions
{
namespace Trigonometric
{
class TanFunctionToken : public FunctionToken
{
public:
    void Operate(std::stack<ValueTokenPtr>& valueTokens,
                 const EvaluationSettings& settings) const override;
};
}
}
}
}

#endif // TANFUNCTIONTOKEN_H
