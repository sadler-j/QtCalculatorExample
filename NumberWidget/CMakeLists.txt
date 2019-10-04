cmake_minimum_required(VERSION 3.4)
project(NumberWidget)

find_package(Qt5Widgets)
find_package(Qt5Gui)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED 1)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

add_library(${PROJECT_NAME}
    numberwidget.cpp
    numberwidget.h
    numberwidget.ui

    Controls/numberpad.cpp
    Controls/numberpad.h
    Controls/numberpad.ui
    Controls/operators.cpp
    Controls/operators.h
    Controls/operators.ui
    Controls/parenthesis.cpp
    Controls/parenthesis.h
    Controls/parenthesis.ui
    Controls/trigonometry.cpp
    Controls/trigonometry.h
    Controls/trigonometry.ui
)

target_link_libraries(${PROJECT_NAME}
    Qt5::Widgets
    Qt5::Gui
)
