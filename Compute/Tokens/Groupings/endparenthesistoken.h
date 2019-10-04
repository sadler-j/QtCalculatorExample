#ifndef ENDPARENTHESISTOKEN_H
#define ENDPARENTHESISTOKEN_H

#include "Tokens/token.h"

namespace Compute
{
namespace Tokens
{
namespace Groupings
{
class EndParenthesisToken : public Token
{
public:
    TokenType GetTokenType() const override;
};
}
}
}

#endif // ENDPARENTHESISTOKEN_H
