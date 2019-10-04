#ifndef MATHTOOLS_H
#define MATHTOOLS_H

namespace Compute
{
class MathTools
{
public:
    static constexpr long double e {2.718281828459045235360287471352662497757247093699959574966967627724076630353L};
    static constexpr long double Pi {3.141592653589793238462643383279502884197169399375105820974944592307816406286L};

    static long double DegreesToRadians(long double degrees);
    static long double RadiansToDegrees(long double radians);
};
}

#endif // MATHTOOLS_H
