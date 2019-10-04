#ifndef FUNCTIONTOKEN_H
#define FUNCTIONTOKEN_H

#include "Tokens/commandtoken.h"

#define FunctionTokenPtr std::shared_ptr<FunctionToken>

namespace Compute
{
namespace Tokens
{
namespace Functions
{
class FunctionToken : public CommandToken
{
public:
    TokenType GetTokenType() const;

    void SetNumberOfArguments(size_t numberOfArguments);

protected:
    size_t GetNumberOfArguments() const;

private:
    size_t numberOfArguments {1};
};
}
}
}

#endif // FUNCTIONTOKEN_H
