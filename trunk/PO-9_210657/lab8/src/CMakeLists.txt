cmake_minimum_required(VERSION 3.5)
set(PROJECT_NAME PO-9_210657_task_8 )
project(${PROJECT_NAME} VERSION 0.1 LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(PROJECT_SOURCES
    main.cpp
    AbstractFactory.h
    Builder.h
)

add_executable(${PROJECT_NAME}
    ${PROJECT_SOURCES}
)

