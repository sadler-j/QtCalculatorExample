#include "tokenizer.h"

#include <ctype.h>
#include <exception>
#include <sstream>

#include "TypeHelper.h"
#include "TokenReaders/functiontokenreader.h"
#include "TokenReaders/operatortokenreader.h"
#include "TokenReaders/valuetokenreader.h"

using namespace Compute;
using namespace Compute::Tokens;
using namespace Compute::TokenReaders;

bool IsStartOfExpression(const std::vector<TokenPtr>& tokens);

TokenPtr ReadFunction(std::istringstream& stream);
TokenPtr ReadOperator(std::istringstream& stream, bool emptyValueStack);
TokenPtr ReadValue(std::istringstream& stream);

std::vector<TokenPtr> Tokenizer::Tokenize(const std::string &expression)
{
    std::vector<TokenPtr> tokens;
    std::istringstream stream {expression};

    while (!stream.eof())
    {
        int character {stream.peek()};
        if (character == EOF)
            break;
        else if (isblank(character))
            stream.ignore();
        else if (isalpha(character))
            tokens.push_back(ReadFunction(stream));
        else if (TypeHelper::IsValue(character))
            tokens.push_back(ReadValue(stream));
        else
            tokens.push_back(ReadOperator(stream, IsStartOfExpression(tokens)));
    }

    return tokens;
}

bool IsStartOfExpression(const std::vector<std::shared_ptr<Token>>& tokens)
{
    return !tokens.size() ||
            tokens.back()->GetTokenType() != TokenType::VALUE;
}

TokenPtr ReadFunction(std::istringstream &stream)
{
    FunctionTokenReader reader;
    return reader.Read(stream);
}

TokenPtr ReadOperator(std::istringstream& stream, bool startOfExpression)
{
    OperatorTokenReader reader {startOfExpression};
    return reader.Read(stream);
}

TokenPtr ReadValue(std::istringstream& stream)
{
    ValueTokenReader reader;
    return reader.Read(stream);
}
