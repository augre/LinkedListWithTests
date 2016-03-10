cmake_minimum_required(VERSION 2.8.7)
project (Tutorial)

# Check for CppUTest and bail out if they don't have it
if(DEFINED ENV{CPPUTEST_HOME})
  message("Using CppUTest found in $ENV{CPPUTEST_HOME}")
else()
  message("CPPUTEST_HOME is not set; You must tell CMake where to find CppUTest")
  return()
endif()

enable_language(C)
enable_language(CXX)

# The version number
#set (Tutorial_VERSION_MAJOR 1)
#set (Tutorial_VERSION_MINOR 0)


include_directories(${PROJECT_SOURCE_DIR})
# include CppUTest headers
include_directories($ENV{CPPUTEST_HOME}/include)
# add cpputest library
add_library(imp_cpputest STATIC IMPORTED)
set_property(TARGET imp_cpputest PROPERTY
             IMPORTED_LOCATION $ENV{CPPUTEST_HOME}/lib/libCppUTest.a)

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)

#add_subdirectory(src)
#add_subdirectory(mocks)
#add_subdirectory(tests)

add_library(LinkedList ./LinkedList.c)
add_library(LinkedListTest ./LinkedListTest.cpp)

add_executable(RunAllTests RunAllTests.cpp)
target_link_libraries(RunAllTests imp_cpputest LinkedListTest LinkedList)



add_custom_command( TARGET RunAllTests COMMAND cd bin && ./RunAllTests POST_BUILD)
