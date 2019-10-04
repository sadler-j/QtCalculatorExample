#include "commatoken.h"

using namespace Compute::Tokens;
using namespace Compute::Tokens::Groupings;

TokenType CommaToken::GetTokenType() const
{
    return TokenType::COMMA;
}
