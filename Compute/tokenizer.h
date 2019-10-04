#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <string>
#include <vector>

#include "Tokens/token.h"

using namespace Compute::Tokens;

namespace Compute
{
class Tokenizer
{
public:
    static std::vector<TokenPtr> Tokenize(const std::string& expression);
};
}

#endif // TOKENIZER_H
