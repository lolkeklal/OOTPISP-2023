cmake_minimum_required(VERSION 3.5)

project(task_06)

set(CMAKE_CXX_STANDARD 17)

if(WIN32)
 set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
 set(CMAKE_MSVC_RUNTIME_LIBRARY MultiThreaded)
 set(CMAKE_CXX_FLAGS_DEBUG "/MTd")
endif()

add_executable(po9_210674_task_06
        src/Source.cpp
)

if(POLICY CMP0091)
  cmake_policy(SET CMP0091 NEW)
endif()

add_library(mylib SHARED include/dllmain.cpp)

target_link_libraries(po9_210674_task_06 dllmain)

add_subdirectory(googletest)

enable_testing()

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})

file(GLOB TEST_SRC_FILES ${PROJECT_SOURCE_DIR}/test/*.cpp)

add_executable(main_test ${TEST_SRC_FILES})

target_link_libraries(main_test gtest gtest_main gmock gmock_main)

target_link_libraries(main_test dllmain)

add_test(UnitTests main_test)
