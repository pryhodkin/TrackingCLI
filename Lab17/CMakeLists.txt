cmake_minimum_required(VERSION 3.15)
project(Lab17)

set(CMAKE_CXX_STANDARD 17)

add_executable(Lab17 main.cpp Command.cpp Command.h History.cpp History.h Log.cpp Log.h CLI.cpp CLI.h StringConsts.cpp StringConsts.h)