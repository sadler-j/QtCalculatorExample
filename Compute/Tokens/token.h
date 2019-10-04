#ifndef TOKEN_H
#define TOKEN_H

#include <memory>

namespace Compute
{
namespace Tokens
{

#define TokenPtr std::shared_ptr<Token>

enum TokenType
{
    VALUE,
    FUNCTION,
    OPERATOR,
    START_GROUP,
    END_GROUP,
    COMMA
};

class Token
{
public:
    virtual TokenType GetTokenType() const = 0;
};

}
}

#endif // TOKEN_H
