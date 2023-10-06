cmake_minimum_required(VERSION 3.10)
project(TextEditor VERSION 2023.10.04.0 LANGUAGES CXX)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_PREFIX_PATH $ENV{QTDIR})
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
add_executable(TextEditor
        main.cpp
        texteditor.cpp
        texteditor.ui
        texteditor.h
)
target_link_libraries(TextEditor Qt${QT_VERSION_MAJOR}::Widgets)
