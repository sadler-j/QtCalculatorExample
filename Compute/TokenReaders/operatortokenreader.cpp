#include "operatortokenreader.h"

#include "Exceptions/computeexception.h"

#include "Tokens/Groupings/commatoken.h"
#include "Tokens/Groupings/endparenthesistoken.h"
#include "Tokens/Groupings/startparenthesistoken.h"

#include "Tokens/Operators/divideoperatortoken.h"
#include "Tokens/Operators/minusoperatortoken.h"
#include "Tokens/Operators/negateoperatortoken.h"
#include "Tokens/Operators/plusoperatortoken.h"
#include "Tokens/Operators/powoperatortoken.h"
#include "Tokens/Operators/timesoperatortoken.h"

using namespace Compute::Exceptions;
using namespace Compute::TokenReaders;
using namespace Compute::Tokens::Groupings;
using namespace Compute::Tokens::Operators;

Token* GetToken(std::istringstream& stream, bool emptyValueStack);
Token* GetNegativeToken(bool emptyValueStack);

OperatorTokenReader::OperatorTokenReader(bool startOfExpression) :
    startOfExpression{startOfExpression}
{ }

TokenPtr OperatorTokenReader::Read(std::istringstream& stream) const
{
    return TokenPtr(GetToken(stream, startOfExpression));
}

Token* GetToken(std::istringstream& stream, bool startOfExpression)
{
    char character;
    stream >> character;

    switch (character) {
    case '+': return new PlusOperatorToken();
    case '-': return GetNegativeToken(startOfExpression);
    case '*': return new TimesOperatorToken();
    case '/': return new DivideOperatorToken();
    case '^': return new PowOperatorToken();

    case '(': return new StartParenthesisToken();
    case ')': return new EndParenthesisToken();
    case ',': return new CommaToken();

    default:
        throw ComputeException("Unknown operator type: " + character);
    }
}

Token* GetNegativeToken(bool startOfExpression)
{
    if (startOfExpression)
        return new NegateOperatorToken();
    else
        return new MinusOperatorToken();
}
