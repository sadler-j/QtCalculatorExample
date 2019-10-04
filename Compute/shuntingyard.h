#ifndef SHUNTINGYARD_H
#define SHUNTINGYARD_H

#include <vector>

#include "Tokens/token.h"

using namespace Compute::Tokens;

namespace Compute
{
class ShuntingYard
{
public:
    static void Shunt(std::vector<TokenPtr>& tokens);
};

}

#endif // SHUNTINGYARD_H
