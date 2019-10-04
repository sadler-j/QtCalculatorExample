#ifndef TYPEHELPER_H
#define TYPEHELPER_H

#include <ctype.h>

namespace Compute
{
class TypeHelper
{
public:
    static bool IsValue(int character)
    {
        return isdigit(character) ||
                character == '.';
    }
};
}

#endif // TYPEHELPER_H
