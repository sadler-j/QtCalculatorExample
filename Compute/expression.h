#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <memory>
#include <string>
#include <vector>

#include "evaluationsettings.h"
#include "NotationType.h"
#include "Tokens/token.h"

using namespace Compute::Tokens;

namespace Compute
{
class Expression
{
public:
    static Expression Build(const std::string& expression,
                            NotationType notation = NotationType::INFIX);

    double Evaluate() const;
    double Evaluate(const EvaluationSettings& settings) const;

private:
    std::vector<TokenPtr> tokens;

    Expression(const std::vector<TokenPtr>& tokens);
};
}

#endif // EXPRESSION_H
