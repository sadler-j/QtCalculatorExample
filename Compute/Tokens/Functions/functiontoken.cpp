#include "functiontoken.h"

using namespace Compute::Tokens;
using namespace Compute::Tokens::Functions;

TokenType FunctionToken::GetTokenType() const
{
    return TokenType::FUNCTION;
}

void FunctionToken::SetNumberOfArguments(size_t numberOfArguments)
{
    this->numberOfArguments = numberOfArguments;
}

size_t FunctionToken::GetNumberOfArguments() const
{
    return numberOfArguments;
}
