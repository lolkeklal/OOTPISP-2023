cmake_minimum_required(VERSION 3.5)
project(task_07 LANGUAGES CXX)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_PREFIX_PATH $ENV{QTDIR})
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
add_executable(po9_210661_task_07
    main.cpp
    l7.cpp
    l7.h
    l7.ui
)
target_link_libraries(po9_210661_task_07 Qt${QT_VERSION_MAJOR}::Widgets)
