cmake_minimum_required(VERSION 3.5)
project(BrokenMusicBox)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")




set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5Widgets REQUIRED)
find_package( Qt5Core)
find_package( Qt5Gui)

set(UI_FILES)

set(RC_FILES)

set(QRC_FILES)

set(SOURCE_FILES main.cpp mainwindow.cpp mainwindow.h Rational.h Rational.cpp Date.h Date.cpp complex.h complex.cpp intVector.h intVector.cpp stringVector.h stringVector.cpp)

add_executable(BrokenMusicBox ${SOURCE_FILES})

target_link_libraries(BrokenMusicBox Qt5::Widgets Qt5::Core)
qt5_use_modules(BrokenMusicBox Core Widgets Gui)