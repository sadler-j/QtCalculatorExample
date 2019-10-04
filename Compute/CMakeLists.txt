cmake_minimum_required(VERSION 3.4)
project(Compute)

set(TEST_NAME ${PROJECT_NAME}_UnitTests)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED 1)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

add_library(${PROJECT_NAME} STATIC
    evaluationsettings.cpp
    evaluationsettings.h
    expression.cpp
    expression.h
    mathtools.cpp
    mathtools.h
    notationtype.h
    shuntingyard.cpp
    shuntingyard.h
    tokenizer.cpp
    tokenizer.h
    typehelper.h

    Exceptions/computeexception.cpp
    Exceptions/computeexception.h

    Tokens/token.h
    Tokens/commandtoken.cpp
    Tokens/commandtoken.h
    Tokens/valuetoken.cpp
    Tokens/valuetoken.h
    Tokens/Functions/absfunctiontoken.cpp
    Tokens/Functions/absfunctiontoken.h
    Tokens/Functions/functiontoken.cpp
    Tokens/Functions/functiontoken.h
    Tokens/Functions/maxfunctiontoken.cpp
    Tokens/Functions/maxfunctiontoken.h
    Tokens/Functions/minfunctiontoken.cpp
    Tokens/Functions/minfunctiontoken.h
    Tokens/Functions/Trigonometric/acosfunctiontoken.cpp
    Tokens/Functions/Trigonometric/acosfunctiontoken.h
    Tokens/Functions/Trigonometric/asinfunctiontoken.cpp
    Tokens/Functions/Trigonometric/asinfunctiontoken.h
    Tokens/Functions/Trigonometric/atanfunctiontoken.cpp
    Tokens/Functions/Trigonometric/atanfunctiontoken.h
    Tokens/Functions/Trigonometric/cosfunctiontoken.cpp
    Tokens/Functions/Trigonometric/cosfunctiontoken.h
    Tokens/Functions/Trigonometric/sinfunctiontoken.cpp
    Tokens/Functions/Trigonometric/sinfunctiontoken.h
    Tokens/Functions/Trigonometric/tanfunctiontoken.cpp
    Tokens/Functions/Trigonometric/tanfunctiontoken.h
    Tokens/Groupings/commatoken.cpp
    Tokens/Groupings/commatoken.h
    Tokens/Groupings/endparenthesistoken.cpp
    Tokens/Groupings/endparenthesistoken.h
    Tokens/Groupings/startparenthesistoken.cpp
    Tokens/Groupings/startparenthesistoken.h
    Tokens/Operators/divideoperatortoken.cpp
    Tokens/Operators/divideoperatortoken.h
    Tokens/Operators/minusoperatortoken.cpp
    Tokens/Operators/minusoperatortoken.h
    Tokens/Operators/negateoperatortoken.cpp
    Tokens/Operators/negateoperatortoken.h
    Tokens/Operators/operatortoken.cpp
    Tokens/Operators/operatortoken.h
    Tokens/Operators/plusoperatortoken.cpp
    Tokens/Operators/plusoperatortoken.h
    Tokens/Operators/powoperatortoken.cpp
    Tokens/Operators/powoperatortoken.h
    Tokens/Operators/timesoperatortoken.cpp
    Tokens/Operators/timesoperatortoken.h

    TokenReaders/functiontokenreader.cpp
    TokenReaders/functiontokenreader.h
    TokenReaders/operatortokenreader.cpp
    TokenReaders/operatortokenreader.h
    TokenReaders/tokenreader.h
    TokenReaders/valuetokenreader.cpp
    TokenReaders/valuetokenreader.h
)

add_executable(${TEST_NAME}
    expressiontest.cpp

    TestCases/ietestcase.h
    TestCases/itestcase.h
    TestCases/testcase.h
)

target_link_libraries(${TEST_NAME}
    gtest
    gtest_main
    ${PROJECT_NAME}
)
