#ifndef PLUSOPERATORTOKEN_H
#define PLUSOPERATORTOKEN_H

#include "operatortoken.h"

namespace Compute
{
namespace Tokens
{
namespace Operators
{
class PlusOperatorToken : public OperatorToken
{
public:
    PlusOperatorToken();

    void Operate(std::stack<ValueTokenPtr>& valueStack,
                 const EvaluationSettings& settings) const override;

    int Precedence() const override;
    bool RightAssociative() const override;
};
}
}
}
#endif // PLUSOPERATORTOKEN_H
