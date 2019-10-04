#ifndef STARTPARENTHESISTOKEN_H
#define STARTPARENTHESISTOKEN_H

#include "Tokens/token.h"

namespace Compute
{
namespace Tokens
{
namespace Groupings
{
class StartParenthesisToken : public Token
{
public:
    TokenType GetTokenType() const override;
};
}
}
}

#endif
