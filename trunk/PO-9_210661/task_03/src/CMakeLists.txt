cmake_minimum_required(VERSION 3.5)
project(task_03   LANGUAGES CXX)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_PREFIX_PATH $ENV{QTDIR})
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
add_executable(po9_210661_task_03
    main.cpp
    t1.h t1.cpp t1.ui
    t2.h t2.cpp t2.ui
    t3.h t3.cpp t3.ui
    t4.h t4.cpp t4.ui
    t5.h t5.cpp t5.ui
    t6.h t6.cpp t6.ui
)
target_link_libraries(po9_210661_task_03 Qt${QT_VERSION_MAJOR}::Widgets)
