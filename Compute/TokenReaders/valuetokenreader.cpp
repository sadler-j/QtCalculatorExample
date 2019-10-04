#include "valuetokenreader.h"

#include "TypeHelper.h"
#include "Tokens/valuetoken.h"

using namespace Compute::TokenReaders;
using namespace Compute::Tokens;

TokenPtr ValueTokenReader::Read(std::istringstream& stream) const
{
    std::string result;
    while (TypeHelper::IsValue(stream.peek()))
    {
        char character;
        stream >> character;
        result += character;
    }

    return ValueTokenPtr(new ValueToken(std::stod(result)));
}
