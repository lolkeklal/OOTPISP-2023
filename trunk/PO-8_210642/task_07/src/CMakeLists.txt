cmake_minimum_required(VERSION 3.5)

project(task_07)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_PREFIX_PATH $ENV{QTDIR})

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

add_executable(po8_210642_task_07
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.cpp
        mainwindow.ui
)

target_link_libraries(po8_210642_task_07 Qt${QT_VERSION_MAJOR}::Widgets)