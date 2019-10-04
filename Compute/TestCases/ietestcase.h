#ifndef IETESTCASE_H
#define IETESTCASE_H

#include "itestcase.h"

template <class Input, class Expect>
class ieTestCase : public iTestCase<Input>
{
public:
    ieTestCase(Input input, Expect expect, const char* test) :
        iTestCase(input, test),
        expect{expect}
    { }

    ieTestCase(Input input, Expect expect, const std::string& test) :
        iTestCase(input, test),
        expect{expect}
    { }

    Expect GetExpected() const
    {
        return expect;
    }

    friend std::ostream& operator<<(std::ostream& output, const ieTestCase& testCase)
    {
        output << static_cast<iTestCase>(testCase);
        return output;
    }

private:
    Expect expect;
};

#endif // IETESTCASE_H
