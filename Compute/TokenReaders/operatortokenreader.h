#ifndef OPERATORTOKENREADER_H
#define OPERATORTOKENREADER_H

#include "tokenreader.h"

namespace Compute
{
namespace TokenReaders
{
class OperatorTokenReader : public TokenReader
{
public:
    OperatorTokenReader(bool startOfExpression);

    TokenPtr Read(std::istringstream &stream) const override;

private:
    bool startOfExpression;
};
}
}

#endif // OPERATORTOKENREADER_H
