#include "functiontokenreader.h"

#include <ctype.h>

#include "mathtools.h"
#include "TypeHelper.h"
#include "Exceptions/computeexception.h"
#include "Tokens/valuetoken.h"
#include "Tokens/Functions/absfunctiontoken.h"
#include "Tokens/Functions/maxfunctiontoken.h"
#include "Tokens/Functions/minfunctiontoken.h"
#include "Tokens/Functions/Trigonometric/acosfunctiontoken.h"
#include "Tokens/Functions/Trigonometric/asinfunctiontoken.h"
#include "Tokens/Functions/Trigonometric/atanfunctiontoken.h"
#include "Tokens/Functions/Trigonometric/cosfunctiontoken.h"
#include "Tokens/Functions/Trigonometric/sinfunctiontoken.h"
#include "Tokens/Functions/Trigonometric/tanfunctiontoken.h"

using namespace Compute;
using namespace Compute::Exceptions;
using namespace Compute::TokenReaders;
using namespace Compute::Tokens;
using namespace Compute::Tokens::Functions;
using namespace Compute::Tokens::Functions::Trigonometric;

#if _MSC_VER
    #pragma warning(push)
    #pragma warning(disable:4307)
#endif

constexpr size_t HASH(const char* value);
constexpr size_t MIX(char character, size_t s);
Token* GetFunctionToken(const std::string& functionName);

TokenPtr FunctionTokenReader::Read(std::istringstream& stream) const
{
    std::string functionName;
    while (isalpha(stream.peek()))
    {
        char character;
        stream >> character;
        character = tolower(character);
        functionName += character;
    }

    return TokenPtr(GetFunctionToken(functionName));
}

constexpr size_t HASH(const char* value)
{
    return *value ? MIX(*value, HASH(value + 1)) : 0;
}

constexpr size_t MIX(char character, size_t s)
{
    return ((s << 7) + ~(s >> 3)) + static_cast<size_t>(~character);
}

Token* GetFunctionToken(const std::string& functionName)
{
    switch (HASH(functionName.c_str()))
    {
    case HASH("abs"): return new AbsFunctionToken();

    case HASH("max"): return new MaxFunctionToken();
    case HASH("min"): return new MinFunctionToken();

    case HASH("acos"): return new ACosFunctionToken();
    case HASH("asin"): return new ASinFunctionToken();
    case HASH("atan"): return new ATanFunctionToken();
    case HASH("cos"): return new CosFunctionToken();
    case HASH("sin"): return new SinFunctionToken();
    case HASH("tan"): return new TanFunctionToken();

    case HASH("pi"): return new ValueToken(MathTools::Pi);

    default:
        throw new ComputeException("Unknown function token type");
    }
}

#if _MSC_VER
    #pragma warning(pop)
#endif
