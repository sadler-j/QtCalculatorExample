#ifndef ABSOLUTEVALUEFUNCTIONTOKEN_H
#define ABSOLUTEVALUEFUNCTIONTOKEN_H

#include "functiontoken.h"

namespace Compute
{
namespace Tokens
{
namespace Functions
{
class AbsFunctionToken : public FunctionToken
{
public:
    void Operate(std::stack<ValueTokenPtr>& valueTokens,
                 const EvaluationSettings& settings) const override;
};
}
}
}

#endif // ABSOLUTEVALUEFUNCTIONTOKEN_H
