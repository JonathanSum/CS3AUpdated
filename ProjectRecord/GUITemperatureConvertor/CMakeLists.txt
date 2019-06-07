cmake_minimum_required(VERSION 3.14)
project(3A)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)



set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp mainwindow.cpp mainwindow.h)
find_package(Qt5Widgets REQUIRED)
find_package( Qt5Core REQUIRED)
find_package( Qt5Gui REQUIRED)
set(UI_FILES)

set(RC_FILES)

set(QRC_FILES)

add_executable(3A ${SOURCE_FILES})

target_link_libraries(3A Qt5::Widgets Qt5::Core Qt5::Gui)

#
#cmake_minimum_required(VERSION 3.14)
#project(3A)
#
#set(CMAKE_INCLUDE_CURRENT_DIR ON)
#
#set(CMAKE_AUTOMOC ON)
#set(CMAKE_AUTOUIC ON)
#set(CMAKE_AUTORCC ON)
#
#
#
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
#
#set(SOURCE_FILES main.cpp widget.h widget.cpp)
#find_package(Qt5Widgets REQUIRED)
#find_package(Qt5Widgets REQUIRED)
#find_package( Qt5Core REQUIRED)
#find_package( Qt5Gui REQUIRED)
#
#
#add_executable(3A ${SOURCE_FILES})
#
#target_link_libraries(3A Qt5::Widgets Qt5::Core)









