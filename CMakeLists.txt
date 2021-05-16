cmake_minimum_required(VERSION 3.20.1)
project(stupid VERSION 0.1)
set(OutputPath "output")
set(CMAKE_CXX_FLAGS_DEBUG_INIT "-Wall")
set(CMAKE_CXX_FLAGS_RELEASE_INIT "-Wall")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g3")
set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)

set(PeerLib "peer")

add_library(${PeerLib} SHARED 
	src/Peer/Attributes/CharacterSizeMask.cpp
	)

target_include_directories(${PeerLib} PRIVATE 
	${PROJECT_SOURCE_DIR}
	)

set_target_properties(${PeerLib} PROPERTIES 
	LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/${OutputPath}/lib
	VERSION ${PROJECT_VERSION}
	SOVERSION 1
	)


set(SharedPointerTest "test_shared_ptr")

add_executable(${SharedPointerTest} 
	test/SharedPointer_test1.cpp
	)


target_include_directories(${SharedPointerTest} PRIVATE 
	${PROJECT_SOURCE_DIR}
	)

set_target_properties(${SharedPointerTest} PROPERTIES 
	RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/${OutputPath}/bin
	)


#set(CommonToolLib "common")
#
#add_library(${CommonToolLib} SHARED 
#	src/Common/SharedPointer.cpp
#	src/Common/UniquePointer.cpp
#	)
#
#target_include_directories(${CommonToolLib} PRIVATE 
#	${PROJECT_SOURCE_DIR}
#	)
#
#set_target_properties(${CommonToolLib} PROPERTIES 
#	LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/${OutputPath}/lib
#	VERSION ${PROJECT_VERSION}
#	SOVERSION 1
#	)
