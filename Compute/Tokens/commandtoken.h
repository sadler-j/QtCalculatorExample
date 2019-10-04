#ifndef COMMANDTOKEN_H
#define COMMANDTOKEN_H

#include <stack>

#include "evaluationsettings.h"
#include "Tokens/token.h"
#include "Tokens/valuetoken.h"

#define CommandTokenPtr std::shared_ptr<CommandToken>

namespace Compute
{
namespace Tokens
{
class CommandToken : public Token
{
public:
    virtual void Operate(std::stack<ValueTokenPtr>& valueStack,
                         const EvaluationSettings& settings) const = 0;

protected:
    static long double PopValue(std::stack<ValueTokenPtr>& valueStack);
};
}
}

#endif // COMMANDTOKEN_H
