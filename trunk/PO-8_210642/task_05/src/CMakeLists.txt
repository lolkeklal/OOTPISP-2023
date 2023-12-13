cmake_minimum_required(VERSION 3.5)

project(task_05)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_PREFIX_PATH  $ENV{QTDIR})

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(Qt6 REQUIRED COMPONENTS Sql)

add_executable(po8_210642_task_05
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)
target_link_libraries(po8_210642_task_05 Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(po8_210642_task_05 Qt6::Sql)
