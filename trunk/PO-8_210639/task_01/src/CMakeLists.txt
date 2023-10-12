cmake_minimum_required(VERSION 3.0.0)

project(lab1 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_PREFIX_PATH $ENV{QTDIR})

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

add_executable(po8_210639_lab1
        main.cpp
        mainwindow.cpp
        mainwindow.ui
        textbox.cpp
        textbox.ui
)

target_link_libraries(po8_210639_lab1 Qt${QT_VERSION_MAJOR}::Widgets)