cmake_minimum_required(VERSION 3.5)

project(task_03)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_PREFIX_PATH $ENV{QTDIR})

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
add_executable(po8_210642_task_03
        main.cpp
        mainwindow.cpp
        mainwindow.ui
        mainwindow.h
        task01.cpp
        task01.h
        task02.cpp
        task02.h
        task03.cpp
        task03.h
        task04.cpp
        task04.h
        task05.cpp
        task05.h
        task06.cpp
        task06.h
)
target_link_libraries(po8_210642_task_03 Qt${QT_VERSION_MAJOR}::Widgets)