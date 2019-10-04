#include "shuntingyard.h"

#include <queue>
#include <stack>
#include <vector>

#include "Exceptions/computeexception.h"
#include "Tokens/Functions/functiontoken.h"
#include "Tokens/Operators/operatortoken.h"

using namespace Compute;
using namespace Compute::Exceptions;
using namespace Compute::Tokens::Functions;
using namespace Compute::Tokens::Operators;

void SortTokens(std::queue<TokenPtr>& tokens,
                std::stack<TokenPtr>& operators,
                std::vector<TokenPtr>& output);

bool PopOperator(TokenPtr top, TokenPtr next);

void ReadFunction(std::queue<TokenPtr>& tokens,
                  std::vector<TokenPtr>& output);
void ReadGroup(std::queue<TokenPtr>& tokens,
               std::vector<TokenPtr>& output);
void ReadOperator(std::queue<TokenPtr>& tokens,
                  std::stack<TokenPtr>& operators,
                  std::vector<TokenPtr>& output);

std::queue<TokenPtr> VectorToQueue(const std::vector<TokenPtr>& vector);

void ShuntingYard::Shunt(std::vector<TokenPtr>& tokens)
{
    std::queue<TokenPtr> toSort {VectorToQueue(tokens)};
    std::stack<TokenPtr> operators;

    tokens.resize(0);
    SortTokens(toSort, operators, tokens);

    if (toSort.size())
        throw ComputeException("Unexpected token");
}

void SortTokens(std::queue<TokenPtr>& tokens,
                std::stack<TokenPtr>& operators,
                std::vector<TokenPtr>& output)
{
    while (tokens.size())
    {
        switch (tokens.front()->GetTokenType())
        {
        case TokenType::VALUE:
            output.push_back(tokens.front());
            tokens.pop();
            break;
        case TokenType::FUNCTION:
            ReadFunction(tokens, output);
            break;
        case TokenType::OPERATOR:
            ReadOperator(tokens, operators, output);
            break;
        case TokenType::START_GROUP:
            ReadGroup(tokens, output);
            break;
        case TokenType::COMMA:
        case TokenType::END_GROUP:
            return;
        default:
            break;
        }
    }

    while (operators.size())
    {
        if (operators.top()->GetTokenType() == TokenType::START_GROUP)
        {
            throw ComputeException("Mismatched parenthesis");
        }

        output.push_back(operators.top());
        operators.pop();
    }
}

bool PopOperator(TokenPtr top, TokenPtr next)
{
    OperatorTokenPtr opTop {std::static_pointer_cast<OperatorToken>(top)};
    OperatorTokenPtr opNext {std::static_pointer_cast<OperatorToken>(next)};

    if (opTop->Precedence() > opNext->Precedence())
        return true;

    return opTop->Precedence() == opNext->Precedence() &&
            opTop->LeftAssociative();
}

void ReadFunction(std::queue<TokenPtr>& tokens,
                  std::vector<TokenPtr>& output)
{
    FunctionTokenPtr function {std::static_pointer_cast<FunctionToken>(tokens.front())};

    //Pop function
    tokens.pop();

    if (tokens.front()->GetTokenType() != TokenType::START_GROUP)
    {
        throw ComputeException("Unexpected token type");
    }

    //Pop start parenthesis
    tokens.pop();

    size_t parameterCount {0};
    while (tokens.size() && tokens.front()->GetTokenType() != TokenType::END_GROUP)
    {
        parameterCount++;
        if (tokens.front()->GetTokenType() == TokenType::COMMA)
        {
            tokens.pop();
        }

        std::stack<TokenPtr> innerOperators;
        SortTokens(tokens, innerOperators, output);

        while(innerOperators.size())
        {
            output.push_back(innerOperators.top());
            innerOperators.pop();
        }
    }

    if (!tokens.size() || tokens.front()->GetTokenType() != TokenType::END_GROUP)
        throw ComputeException("Parenthesis mismatch");

    //Pop end parenthesis
    tokens.pop();

    function->SetNumberOfArguments(parameterCount);
    output.push_back(function);
}

void ReadGroup(std::queue<TokenPtr>& tokens,
               std::vector<TokenPtr>& output)
{
    //Pop start parethesis
    tokens.pop();

    while (tokens.size() && tokens.front()->GetTokenType() != TokenType::END_GROUP)
    {
        if (tokens.front()->GetTokenType() == TokenType::COMMA)
            throw ComputeException("Unexpected comma");

        std::stack<TokenPtr> innerOperators;
        SortTokens(tokens, innerOperators, output);

        while(innerOperators.size())
        {
            output.push_back(innerOperators.top());
            innerOperators.pop();
        }
    }

    if (!tokens.size() || tokens.front()->GetTokenType() != TokenType::END_GROUP)
        throw ComputeException("Parenthesis mismatch");

    //Pop end parenthesis
    tokens.pop();
}

void ReadOperator(std::queue<std::shared_ptr<Token>>& tokens,
                  std::stack<std::shared_ptr<Token>>& operators,
                  std::vector<std::shared_ptr<Token>>& output)
{
    while(operators.size() && tokens.size() &&
          PopOperator(operators.top(), tokens.front()))
    {
        output.push_back(operators.top());
        operators.pop();
    }

    operators.push(tokens.front());
    tokens.pop();
}

std::queue<TokenPtr> VectorToQueue(const std::vector<TokenPtr>& vector)
{
    std::queue<TokenPtr> result;
    for (TokenPtr token : vector)
    {
        result.push(token);
    }

    return result;
}
