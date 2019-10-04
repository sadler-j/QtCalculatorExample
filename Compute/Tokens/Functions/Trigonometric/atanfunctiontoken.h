#ifndef ATANFUNCTIONTOKEN_H
#define ATANFUNCTIONTOKEN_H

#include "Tokens/Functions/functiontoken.h"

namespace Compute
{
namespace Tokens
{
namespace Functions
{
namespace Trigonometric
{
class ATanFunctionToken : public FunctionToken
{
public:
    void Operate(std::stack<ValueTokenPtr>& valueTokens,
                 const EvaluationSettings& settings) const override;
};
}
}
}
}

#endif // ATANFUNCTIONTOKEN_H
