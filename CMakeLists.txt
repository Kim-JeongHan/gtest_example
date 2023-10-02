cmake_minimum_required(VERSION 3.16)

project(gtest_test LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17) 

file(GLOB SRC
    "src/*.cpp" "src/*.c")



add_library(${PROJECT_NAME}_lib
    ${SRC}
)

target_include_directories(
    ${PROJECT_NAME}_lib 
    PUBLIC ${CMAKE_SOURCE_DIR}/include
)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG        v1.14.0
)
FetchContent_GetProperties(googletest)
if(NOT googletest_POPULATED)
    FetchContent_Populate(googletest)
    add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
    include_directories(${gtest_SOURCE_DIR}/include ${gmock_SOURCE_DIR}/include)
endif()

add_executable(gtest_ex test/gtest_ex.cpp)
target_link_libraries(
    gtest_ex  
    gtest 
    gtest_main 
    ${PROJECT_NAME}_lib
)