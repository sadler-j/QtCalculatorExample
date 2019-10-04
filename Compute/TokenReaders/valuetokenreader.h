#ifndef VALUETOKENREADER_H
#define VALUETOKENREADER_H

#include "tokenreader.h"

namespace Compute
{
namespace TokenReaders
{
class ValueTokenReader : public TokenReader
{
public:
    TokenPtr Read(std::istringstream& stream) const;
};
}
}

#endif // VALUETOKENREADER_H
