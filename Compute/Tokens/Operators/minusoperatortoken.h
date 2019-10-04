#ifndef MINUSOPERATORTOKEN_H
#define MINUSOPERATORTOKEN_H

#include "operatortoken.h"

namespace Compute
{
namespace Tokens
{
namespace Operators
{
class MinusOperatorToken : public OperatorToken
{
public:
    void Operate(std::stack<ValueTokenPtr>& valueStack,
                 const EvaluationSettings& settings) const override;

    int Precedence() const override;
    bool RightAssociative() const override;
};
}
}
}

#endif // MINUSOPERATORTOKEN_H
