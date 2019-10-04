#ifndef VALUETOKEN_H
#define VALUETOKEN_H

#include "token.h"

#define ValueTokenPtr std::shared_ptr<ValueToken>

namespace Compute
{
namespace Tokens
{
class ValueToken : public Token
{
public:
    ValueToken(long double value);

    TokenType GetTokenType() const override;

    long double GetValue() const;

private:
    long double value;
};
}
}

#endif // VALUETOKEN_H
