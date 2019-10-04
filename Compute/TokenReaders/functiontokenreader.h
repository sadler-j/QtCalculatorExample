#ifndef FUNCTIONTOKENREADER_H
#define FUNCTIONTOKENREADER_H

#include "tokenreader.h"

namespace Compute
{
namespace TokenReaders
{
class FunctionTokenReader : public TokenReader
{
public:
    TokenPtr Read(std::istringstream& stream) const;
};
}
}

#endif // FUNCTIONTOKENREADER_H
