#include "endparenthesistoken.h"

using namespace Compute::Tokens;
using namespace Compute::Tokens::Groupings;

TokenType EndParenthesisToken::GetTokenType() const
{
    return TokenType::END_GROUP;
}
