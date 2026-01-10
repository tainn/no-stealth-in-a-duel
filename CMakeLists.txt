cmake_minimum_required(VERSION 3.20)
project(NoStealthInADuel)

set(CMAKE_CXX_STANDARD 14)
include_directories("$ENV{BZFLAG_INCLUDE_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "$ENV{BZFLAG_PLUGIN_DIR}")

add_library(NoStealthInADuel SHARED src/NoStealthInADuel.cpp)
set_target_properties(NoStealthInADuel PROPERTIES PREFIX "")
