#ifndef COMMATOKEN_H
#define COMMATOKEN_H

#include "Tokens/token.h"

namespace Compute
{
namespace Tokens
{
namespace Groupings
{
class CommaToken : public Token
{
public:
    TokenType GetTokenType() const override;
};
}
}
}

#endif // COMMATOKEN_H
