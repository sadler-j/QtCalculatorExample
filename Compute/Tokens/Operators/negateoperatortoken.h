#ifndef NEGATEOPERATORTOKEN_H
#define NEGATEOPERATORTOKEN_H

#include "operatortoken.h"

namespace Compute
{
namespace Tokens
{
namespace Operators
{
class NegateOperatorToken : public OperatorToken
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

#endif // NEGATEOPERATORTOKEN_H
