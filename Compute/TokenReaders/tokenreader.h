#ifndef TOKENREADER_H
#define TOKENREADER_H

#include <sstream>

#include "Tokens/token.h"

using namespace Compute::Tokens;

namespace Compute
{
namespace TokenReaders
{
class TokenReader
{
public:
    virtual TokenPtr Read(std::istringstream& stream) const = 0;
};
}
}

#endif // TOKENREADER_H
