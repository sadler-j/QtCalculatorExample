#ifndef MAXFUNCTIONTOKEN_H
#define MAXFUNCTIONTOKEN_H

#include "functiontoken.h"

namespace Compute
{
namespace Tokens
{
namespace Functions
{
class MaxFunctionToken : public FunctionToken
{
public:
    void Operate(std::stack<ValueTokenPtr>& valueTokens,
                 const EvaluationSettings& settings) const override;
};
}
}
}

#endif // MAXFUNCTIONTOKEN_H
