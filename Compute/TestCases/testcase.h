#ifndef TESTCASE_H
#define TESTCASE_H

#include <iostream>
#include <string>

class TestCase
{
public:
    TestCase(const char* test) :
        test{test}
    { }

    TestCase(const std::string& test) :
        test{test}
    { }

    friend std::ostream& operator<<(std::ostream& output, const TestCase& testCase)
    {
        output << testCase.test;
        return output;
    }

private:
    std::string test;
};

#endif // TESTCASE_H
