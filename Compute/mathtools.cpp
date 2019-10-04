#include "mathtools.h"

using namespace Compute;

long double MathTools::DegreesToRadians(long double degrees)
{
    return degrees * Pi / 180.0L;
}

long double MathTools::RadiansToDegrees(long double radians)
{
    return radians * 180.0L / Pi;
}
