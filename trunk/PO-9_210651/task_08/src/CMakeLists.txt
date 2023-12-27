cmake_minimum_required(VERSION 3.5)

project(po9_210651_task_08 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_executable(po9_210651_task_08
  main.cpp
  AbstractFactory.h
  Builder.h
)
target_link_libraries(po9_210651_task_08 Qt${QT_VERSION_MAJOR}::Core)
