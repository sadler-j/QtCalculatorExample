#include "startparenthesistoken.h"

using namespace Compute::Tokens;
using namespace Compute::Tokens::Groupings;

TokenType StartParenthesisToken::GetTokenType() const
{
    return TokenType::START_GROUP;
}
