cmake_minimum_required(VERSION 3.5)
project(task_03 LANGUAGES CXX)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_PREFIX_PATH $ENV{QTDIR})
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
add_executable(po9_210665_task_03
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        form.ui
        form.h
        form.cpp
        form2.ui
        form2.h
        form2.cpp
        form21.ui
        form21.h
        form21.cpp
        form3.ui
        form3.h
        form3.cpp
        form4.ui
        form4.h
        form4.cpp
        form5.ui
        form5.h
        form5.cpp
        form6.ui
        form6.h
        form6.cpp
)
target_link_libraries(po9_210665_task_03 Qt${QT_VERSION_MAJOR}::Widgets)