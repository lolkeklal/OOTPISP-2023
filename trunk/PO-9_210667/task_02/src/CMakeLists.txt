cmake_minimum_required(VERSION 3.5)
project(lab_2_OOP LANGUAGES CXX)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_PREFIX_PATH $ENV{QTDIR})
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

add_executable(po9_210667_lab2
        main.cpp
        texteditor.cpp
        texteditor.h
        texteditor.ui
	texteditor.qrc
)
target_link_libraries(po9_210667_lab2 Qt${QT_VERSION_MAJOR}::Widgets)