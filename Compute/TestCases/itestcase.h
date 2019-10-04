#ifndef ITESTCASE_H
#define ITESTCASE_H

#include "testcase.h"

template <class Input>
class iTestCase : public TestCase
{
public:
    iTestCase(Input input, const char* test) :
        TestCase(test),
        input{input}
    { }

    iTestCase(Input input, const std::string& test) :
        TestCase(test),
        input{input}
    { }

    Input GetInput() const
    {
        return input;
    }

    friend std::ostream& operator<<(std::ostream& output, const iTestCase& testCase)
    {
        output << static_cast<TestCase>(testCase);
        return output;
    }

private:
    Input input;
};

#endif // ITESTCASE_H
