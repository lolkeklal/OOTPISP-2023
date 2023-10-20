cmake_minimum_required (VERSION 3.5)
project (OOTPISP) 

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_PREFIX_PATH $ENV{QTDIR})

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

# Search for directories simular to "trunk/PO000xxyy/task_0x/src/"
file(GLOB V_GLOB RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "trunk/*/*/src")
foreach(item ${V_GLOB})
	#if(IS_DIRECTORY ${item})
		message( "Find \"${item}\"" )
		add_subdirectory(${item})		
	#endif()
endforeach()

