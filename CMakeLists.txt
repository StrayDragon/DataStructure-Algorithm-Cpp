cmake_minimum_required(VERSION 3.10)

project(DataStructure-Algorithm-Cpp)

set(CMAKE_CXX_STANDARD 11)

set(Lib_GoogleTest lib/googletest)

#Add the google test subdirectory
add_subdirectory(${Lib_GoogleTest})
#include googletest/include dir
include_directories(${Lib_GoogleTest}/googletest/include)
#include the googlemock/include dir
include_directories(${Lib_GoogleTest}/googlemock/include)

set(TEMP_SOURCE_FILE
        #        src/ADTs/interfaces/Graph.h
        #        src/ADTs/AdjacencyMatrixGraph.h
        #        src/ADTs/AdjacencyMatrixGraph.cpp
        # src/Experiments/adts_specific_AdjanceListGraph/AdjListGraph.h
        src/ADTs/TriNode.hpp
        src/Utilities/Rc.hpp
        )

set(SOURCE_FILE
        # ${TEMP_SOURCE_FILE}
        test/unit_main.cpp
        test/unit_ADTs_List_Interface.cpp
        test/unit_ADTs_Stack_Interface.cpp
        test/unit_ADTs_Queue_Interface.cpp
        test/unit_ADTs_Tree_Interface.cpp
        test/unit_ADTs_Heap_Interface.cpp
        test/unit_ADTs_Graph_Interface.cpp
        test/unit_Algorithms_RawArray_Sort.cpp
        )
      
set(EXECUTABLE_OUTPUT_PATH "bin")

add_executable(test_main ${SOURCE_FILE})

# Link with GoogleTest
target_link_libraries(test_main gtest gtest_main)

# Link with GoogleMock
target_link_libraries(test_main gmock gmock_main)


#find_package(Catch2 REQUIRED)
#add_executable(DataStructure-Algorithm-Cpp Tests/test_adts_list.cpp)
#
#target_link_libraries(DataStructure-Algorithm-Cpp Catch2::Catch2)
#
#include(CTest)
#include(Catch)
#catch_discover_tests(DataStructure-Algorithm-Cpp)
