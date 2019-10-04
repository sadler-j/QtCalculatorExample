#include "gtest/gtest.h"

#include "evaluationsettings.h"
#include "expression.h"

#include "Exceptions/computeexception.h"

#include "TestCases/itestcase.h"
#include "TestCases/ietestcase.h"

using namespace Compute;
using namespace Compute::Exceptions;

const long double PI {3.14159265358979};

iTestCase<char*> invalidEvaluations[]
{
    iTestCase<char*>("abs()", "AbsTooFewArguments"),
    iTestCase<char*>("abs(1,2)", "AbsTooManyArguments"),

    iTestCase<char*>("min()", "MinTooFewArguments"),
    iTestCase<char*>("max()", "MaxTooFewArguments"),

    iTestCase<char*>("acos()", "ACosTooFewArguments"),
    iTestCase<char*>("asin()", "ASinTooFewArguments"),
    iTestCase<char*>("atan()", "ATanTooFewArguments"),
    iTestCase<char*>("cos()", "CosTooFewArguments"),
    iTestCase<char*>("sin()", "SinTooFewArguments"),
    iTestCase<char*>("tan()", "TanTooFewArguments"),
    iTestCase<char*>("acos(0,1)", "ACosTooManyArguments"),
    iTestCase<char*>("asin(0,1)", "ASinTooManyArguments"),
    iTestCase<char*>("atan(0,1)", "ATanTooManyArguments"),
    iTestCase<char*>("cos(0,1)", "CosTooManyArguments"),
    iTestCase<char*>("sin(0,1)", "SinTooManyArguments"),
    iTestCase<char*>("tan(0,1)", "TanTooManyArguments")
};

iTestCase<char*> invalidExpressions[]
{
    iTestCase<char*>("2+3)", "MissingStartParenthesis"),
    iTestCase<char*>("2*(3+5", "MissingEndParenthesis"),
    iTestCase<char*>("min2,5)", "FunctionMissingStartParenthesis"),
    iTestCase<char*>("min(2,5", "FunctionMissingEndParenthesis")
};

ieTestCase<char*, double> validExpressions[]
{
    ieTestCase<char*, double>("0", 0.0, "Value"),
    ieTestCase<char*, double>("pi", 3.14159265358979, "PiConstant"),

    ieTestCase<char*, double>("5+7", 12.0, "SimpleAdd"),
    ieTestCase<char*, double>("5-7", -2.0, "SimpleSubtract"),
    ieTestCase<char*, double>("5*7", 35.0, "SimpleMultiply"),
    ieTestCase<char*, double>("5/7", 5.0/7.0, "SimpleDivide"),
    ieTestCase<char*, double>("5^7", 78125.0, "SimplePower"),

    ieTestCase<char*, double>("-2+2", 0.0, "SimpleAddWithNegativeInitialValue"),
    ieTestCase<char*, double>("-2-2", -4.0, "SimpleSubtractWithNegativeInitialValue"),
    ieTestCase<char*, double>("-2*2", -4.0, "SimpleMultiplyWithNegativeInitialValue"),
    ieTestCase<char*, double>("-2/2", -1.0, "SimpleDivideWithNegativeInitialValue"),
    ieTestCase<char*, double>("-2^2", -4.0, "SimplePowerWithNegativeInitialValue"),

    ieTestCase<char*, double>("2+-2", 0.0, "SimpleAddWithNegativeFinalValue"),
    ieTestCase<char*, double>("2--2", 4.0, "SimpleSubtractWithNegativeFinalValue"),
    ieTestCase<char*, double>("2*-2", -4.0, "SimpleMultiplyWithNegativeFinalValue"),
    ieTestCase<char*, double>("2/-2", -1.0, "SimpleDivideWithNegativeFinalValue"),
    ieTestCase<char*, double>("2^-2", 0.25, "SimplePowerWithNegativeFinalValue"),

    ieTestCase<char*, double>("abs(1)", 1.0, "AbsOfPositiveValue"),
    ieTestCase<char*, double>("abs(-1)", 1.0, "AbsOfNegativeValue"),

    ieTestCase<char*, double>("max(2,5)", 5.0, "MaxOfTwoValues"),
    ieTestCase<char*, double>("max(2,5,-3,1)", 5.0, "MaxOfMultipleValues"),
    ieTestCase<char*, double>("min(2,5)", 2.0, "MinOfTwoValues"),
    ieTestCase<char*, double>("min(2,5,-3,1)", -3.0, "MinOfMultipleValues"),

    ieTestCase<char*, double>("acos(1)", 0.0, "SimpleACosOf1"),
    ieTestCase<char*, double>("acos(0)", PI/2.0, "SimpleACosOf0"),
    ieTestCase<char*, double>("acos(-1)", PI, "SimpleACosOfNegative1"),
    ieTestCase<char*, double>("asin(0)", 0.0, "SimpleASinOf0"),
    ieTestCase<char*, double>("asin(1)", PI/2.0, "SimpleASinOf1"),
    ieTestCase<char*, double>("asin(-1)", -PI/2.0, "SimpleASinOfNegative1"),
    ieTestCase<char*, double>("atan(0)", 0.0, "SimpleATanOf0"),
    ieTestCase<char*, double>("atan(1)", PI/4, "SimpleATanOf1"),
    ieTestCase<char*, double>("atan(-1)", -PI/4, "SimpleATanOfNegative1"),
    ieTestCase<char*, double>("cos(0)", 1.0, "SimpleCosOf0"),
    ieTestCase<char*, double>("cos(pi/2)", 0.0, "SimpleCosOfPiOver2"),
    ieTestCase<char*, double>("cos(pi)", -1.0, "SimpleCosOfPi"),
    ieTestCase<char*, double>("cos(3*pi/2)", 0.0, "SimpleCosOf3PiOver2"),
    ieTestCase<char*, double>("sin(0)", 0.0, "SimpleSinOf0"),
    ieTestCase<char*, double>("sin(pi/2)", 1.0, "SimpleSinOfPiOver2"),
    ieTestCase<char*, double>("sin(pi)", 0.0, "SimpleSinOfPi"),
    ieTestCase<char*, double>("sin(3*pi/2)", -1.0, "SimpleSinOf3PiOver2"),
    ieTestCase<char*, double>("tan(0)", 0.0, "SimpleTanOf0"),
    ieTestCase<char*, double>("tan(pi)", 0.0, "SimpleTanOfPi"),

    ieTestCase<char*, double>("3+4*2/(1-5)^2^3", 3.0001220703125, "ComplicatedExpression"),
    ieTestCase<char*, double>("sin(max(2,3)/3*pi)", 0.0, "ComplicatedExpressionWithFunctions")
};

ieTestCase<char*, double> validDegreeExpressions[]
{
    ieTestCase<char*, double>("acos(1)", 0.0, "SimpleACosOf1"),
    ieTestCase<char*, double>("acos(0)", 90.0, "SimpleACosOf0"),
    ieTestCase<char*, double>("acos(-1)", 180.0, "SimpleACosOfNegative1"),
    ieTestCase<char*, double>("asin(0)", 0.0, "SimpleASinOf0"),
    ieTestCase<char*, double>("asin(1)", 90.0, "SimpleASinOf1"),
    ieTestCase<char*, double>("asin(-1)", -90.0, "SimpleASinOfNegative1"),
    ieTestCase<char*, double>("atan(0)", 0.0, "SimpleATanOf0"),
    ieTestCase<char*, double>("atan(1)", 45.0, "SimpleATanOf1"),
    ieTestCase<char*, double>("atan(-1)", -45.0, "SimpleATanOfNegative1"),
    ieTestCase<char*, double>("cos(0)", 1.0, "SimpleCosOf0"),
    ieTestCase<char*, double>("cos(90)", 0.0, "SimpleCosOfPiOver2"),
    ieTestCase<char*, double>("cos(180)", -1.0, "SimpleCosOfPi"),
    ieTestCase<char*, double>("cos(270)", 0.0, "SimpleCosOf3PiOver2"),
    ieTestCase<char*, double>("sin(0)", 0.0, "SimpleSinOf0"),
    ieTestCase<char*, double>("sin(90)", 1.0, "SimpleSinOfPiOver2"),
    ieTestCase<char*, double>("sin(180)", 0.0, "SimpleSinOfPi"),
    ieTestCase<char*, double>("sin(270)", -1.0, "SimpleSinOf3PiOver2"),
    ieTestCase<char*, double>("tan(0)", 0.0, "SimpleTanOf0"),
    ieTestCase<char*, double>("tan(180)", 0.0, "SimpleTanOfPi")
};

class InvalidEvaluationTests : public testing::TestWithParam<iTestCase<char*>> {};

class InvalidExpressionTests : public testing::TestWithParam<iTestCase<char*>> {};

class ValidExpressionTests : public testing::TestWithParam<ieTestCase<char*, double>> {};

class ValidDegreeExpressionTests : public testing::TestWithParam<ieTestCase<char*, double>> {};

INSTANTIATE_TEST_SUITE_P(InvalidEvaluations, InvalidEvaluationTests,
                         testing::ValuesIn(invalidEvaluations));

INSTANTIATE_TEST_SUITE_P(InvalidExpressions, InvalidExpressionTests,
                         testing::ValuesIn(invalidExpressions));

INSTANTIATE_TEST_SUITE_P(ValidExpressions, ValidExpressionTests,
                         testing::ValuesIn(validExpressions));

INSTANTIATE_TEST_SUITE_P(ValidDegreeExpressions, ValidDegreeExpressionTests,
                         testing::ValuesIn(validDegreeExpressions));

TEST_P(InvalidEvaluationTests, GivenExpressionWithFunctionsThatAreMalformed_ThrowsException)
{
    const iTestCase<char*> testCase {GetParam()};

    const Expression expression {Expression::Build(testCase.GetInput())};
    EXPECT_THROW(expression.Evaluate(), ComputeException);
}

TEST_P(InvalidExpressionTests, GivenInvalidExpressions_ThrowsException)
{
    const iTestCase<char*> testCase {GetParam()};

    EXPECT_THROW(Expression::Build(testCase.GetInput()), ComputeException);
}

TEST_P(ValidExpressionTests, GivenValidExpression_ReturnsValidResult)
{
    const ieTestCase<char*, double> testCase {GetParam()};

    const Expression expr {Expression::Build(testCase.GetInput())};
    const double result {expr.Evaluate()};

    const double absoluteError {0.000000000001};
    EXPECT_NEAR(testCase.GetExpected(), result, absoluteError);
}

TEST_P(ValidDegreeExpressionTests, GivenValidExpressionWithDegrees_ReturnsValidResult)
{
    const ieTestCase<char*, double> testCase {GetParam()};

    EvaluationSettings settings;
    settings.IsRadians(false);

    const Expression expr {Expression::Build(testCase.GetInput())};
    const double result {expr.Evaluate(settings)};

    const double absoluteError {0.000000000001};
    EXPECT_NEAR(testCase.GetExpected(), result, absoluteError);
}
