#include "operatortoken.h"

using namespace Compute::Tokens;
using namespace Compute::Tokens::Operators;

bool OperatorToken::LeftAssociative() const
{
    return !RightAssociative();
}

TokenType OperatorToken::GetTokenType() const
{
    return TokenType::OPERATOR;
}
