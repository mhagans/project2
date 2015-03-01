cmake_minimum_required(VERSION 2.8.4)
project(Project2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp LexicalAnalyzer.cpp SyntaxAnalyzer.cpp)
add_executable(Project2 ${SOURCE_FILES})