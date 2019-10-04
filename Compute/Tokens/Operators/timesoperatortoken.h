#ifndef TIMESOPERATORTOKEN_H
#define TIMESOPERATORTOKEN_H

#include "operatortoken.h"

namespace Compute
{
namespace Tokens
{
namespace Operators
{
class TimesOperatorToken : public OperatorToken
{
public:
    TimesOperatorToken();

    void Operate(std::stack<ValueTokenPtr>& valueStack,
                 const EvaluationSettings& settings) const override;

    int Precedence() const override;
    bool RightAssociative() const override;
};
}
}
}

#endif // TIMESOPERATORTOKEN_H
