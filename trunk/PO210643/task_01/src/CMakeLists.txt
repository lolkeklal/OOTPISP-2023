cmake_minimum_required(VERSION 3.26)

project(task_01)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_PREFIX_PATH $ENV{QTDIR})

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

add_executable(
        main.cpp
        mainwindow.cpp
        mainwindow.ui
        textreviwer.cpp
        textreviwer.ui
)

target_link_libraries(lab1 Qt${QT_VERSION_MAJOR}::Widgets)