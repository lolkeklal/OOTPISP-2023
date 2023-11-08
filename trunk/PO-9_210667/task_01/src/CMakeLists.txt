cmake_minimum_required(VERSION 3.5)

project(untitled9 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_PREFIX_PATH $ENV{QTDIR})

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

add_executable(po9_210667_lab1
        main.cpp
        widget.cpp
        widget.h
        widget.ui
)


target_link_libraries(po9_210667_lab1 Qt${QT_VERSION_MAJOR}::Widgets)
