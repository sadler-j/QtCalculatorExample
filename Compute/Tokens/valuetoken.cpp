#include "valuetoken.h"

using namespace Compute::Tokens;

ValueToken::ValueToken(long double value) :
    value{value}
{ }

TokenType ValueToken::GetTokenType() const
{
    return TokenType::VALUE;
}

long double ValueToken::GetValue() const
{
    return value;
}
