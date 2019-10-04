#ifndef MINFUNCTIONTOKEN_H
#define MINFUNCTIONTOKEN_H

#include "functiontoken.h"

namespace Compute
{
namespace Tokens
{
namespace Functions
{
class MinFunctionToken : public FunctionToken
{
public:
    void Operate(std::stack<ValueTokenPtr>& valueTokens,
                 const EvaluationSettings& settings) const override;
};
}
}
}

#endif // MINFUNCTIONTOKEN_H
