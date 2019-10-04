#ifndef POWOPERATORTOKEN_H
#define POWOPERATORTOKEN_H

#include "operatortoken.h"

namespace Compute
{
namespace Tokens
{
namespace Operators
{
class PowOperatorToken : public OperatorToken
{
public:
    PowOperatorToken();

    void Operate(std::stack<ValueTokenPtr>& valueStack,
                 const EvaluationSettings& settings) const override;

    int Precedence() const override;
    bool RightAssociative() const override;
};
}
}
}

#endif // POWOPERATORTOKEN_H
