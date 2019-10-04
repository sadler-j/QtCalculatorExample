#ifndef OPERATORTOKEN_H
#define OPERATORTOKEN_H

#include <stack>

#include "Tokens/commandtoken.h"

#define OperatorTokenPtr std::shared_ptr<OperatorToken>

namespace Compute
{
namespace Tokens
{
namespace Operators
{
class OperatorToken : public CommandToken
{
public:
    virtual int Precedence() const = 0;
    virtual bool RightAssociative() const = 0;

    TokenType GetTokenType() const override;

    bool LeftAssociative() const;
};
}
}
}

#endif // OPERATORTOKEN_H
