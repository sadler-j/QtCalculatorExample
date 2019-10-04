cmake_minimum_required(VERSION 3.4)
project(Calculator)

find_package(Qt5Widgets)
find_package(Qt5Gui)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED 1)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(COMPUTE_LIB Compute)
set(NUMBER_WIDGET_LIB NumberWidget)

include_directories(${COMPUTE_LIB})
include_directories(${NUMBER_WIDGET_LIB})

add_subdirectory(${COMPUTE_LIB})
add_subdirectory(${NUMBER_WIDGET_LIB})

IF (NOT TARGET gtest)
    # Prevent GoogleTest from overriding our compiler/linker options
    # when building with Visual Studio.
    # You don't need to modify this.
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    add_subdirectory(libs/googletest)
ENDIF()

add_executable(${PROJECT_NAME}
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
)

target_link_libraries(${PROJECT_NAME}
    Qt5::Widgets
    Qt5::Gui
    ${COMPUTE_LIB}
    ${NUMBER_WIDGET_LIB}
)
