#include "commandtoken.h"

using namespace Compute::Tokens;

long double CommandToken::PopValue(std::stack<std::shared_ptr<ValueToken>>& valueStack)
{
    long double value {valueStack.top()->GetValue()};
    valueStack.pop();

    return value;
}
