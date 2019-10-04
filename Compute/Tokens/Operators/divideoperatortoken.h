#ifndef DIVIDEOPERATORTOKEN_H
#define DIVIDEOPERATORTOKEN_H

#include "operatortoken.h"

namespace Compute
{
namespace Tokens
{
namespace Operators
{
class DivideOperatorToken : public OperatorToken
{
public:
    DivideOperatorToken();

    void Operate(std::stack<ValueTokenPtr>& valueStack,
                 const EvaluationSettings& settings) const override;

    int Precedence() const override;
    bool RightAssociative() const override;
};
}
}
}

#endif // DIVIDEOPERATORTOKEN_H
