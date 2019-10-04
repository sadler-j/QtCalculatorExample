#include "expression.h"

#include <stack>

#include "shuntingyard.h"
#include "tokenizer.h"
#include "Exceptions/computeexception.h"
#include "Tokens/commandtoken.h"
#include "Tokens/valuetoken.h"

using namespace Compute;
using namespace Compute::Exceptions;
using namespace Compute::Tokens;

Expression Expression::Build(const std::string &expression, NotationType notation)
{
    std::vector<TokenPtr> tokens {Tokenizer::Tokenize(expression)};

    if (notation == NotationType::INFIX)
        ShuntingYard::Shunt(tokens);

    return Expression(tokens);
}

Expression::Expression(const std::vector<TokenPtr>& tokens) :
    tokens{tokens}
{ }

double Expression::Evaluate() const
{
    EvaluationSettings settings;
    return Evaluate(settings);
}

double Expression::Evaluate(const EvaluationSettings& settings) const
{
    std::stack<ValueTokenPtr> valueTokens;
    for (TokenPtr token : tokens)
    {
        if (token->GetTokenType() == TokenType::VALUE)
        {
            valueTokens.push(std::static_pointer_cast<ValueToken>(token));
        }
        else
        {
            std::static_pointer_cast<CommandToken>(token)->Operate(valueTokens, settings);
        }
    }

    if (valueTokens.size() != 1)
        throw ComputeException("Expression ended prematurely");

    return valueTokens.top()->GetValue();
}
