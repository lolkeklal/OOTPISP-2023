cmake_minimum_required(VERSION 3.5)
project(task_02_210668 LANGUAGES CXX)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_PREFIX_PATH $ENV{QTDIR})
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
add_executable(task_02_210668
        main.cpp
        texteditor.h
        texteditor.cpp
        texteditor.ui
        icons.qrc
)
target_link_libraries(task_02_210668 Qt${QT_VERSION_MAJOR}::Widgets)
