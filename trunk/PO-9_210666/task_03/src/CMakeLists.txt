cmake_minimum_required(VERSION 3.5)
project(po9_210666_lab3 LANGUAGES CXX)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_PREFIX_PATH $ENV{QTDIR})
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
add_executable(po9_210666_lab3
        main.cpp
        task1.cpp
        task1.h
        task1.ui
        task2.h
        task2.cpp
        task2.ui
        task3.cpp
        task3.h
        task3.ui
        task4.h
        task4.cpp
        task4.ui
        task5.cpp
        task5.h
        task5.ui
        task6.h
        task6.cpp
        task6.ui
        choosetask.h
        choosetask.cpp
        choosetask.ui
)
target_link_libraries(po9_210666_lab3  Qt${QT_VERSION_MAJOR}::Widgets)