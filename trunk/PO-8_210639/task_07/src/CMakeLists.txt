cmake_minimum_required(VERSION 3.5)

project(task_07)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_PREFIX_PATH $ENV{QTDIR})

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

add_executable(po8_210639_task_07_abstract_factory
        abstractfactory.cpp
        mazefactory.cpp
        room.cpp
        door.cpp
        concreteRoom.cpp
        concreteDoor.cpp
        concreteMazeFactory.cpp
 )

add_executable(po8_210639_task_07_builder
        buildermain.cpp
        builder.cpp
        eyes.cpp
        ears.cpp
        nose.cpp
        mouth.cpp
        hair.cpp
        uglyfacebuilder.cpp
        goodfacebuilder.cpp
        smilefacebuilder.cpp
        faceDirector.cpp
)


target_link_libraries(po8_210639_task_07_abstract_factory Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(po8_210639_task_07_builder Qt${QT_VERSION_MAJOR}::Widgets)