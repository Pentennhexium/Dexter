cmake_minimum_required(VERSION 3.15)
project(dexter CXX)

add_library(dexter src/Identifier.cpp)
target_include_directories(dexter PUBLIC include)

set_target_properties(dexter PROPERTIES PUBLIC_HEADER "include/Identifier.h")
install(TARGETS dexter)
