cmake_minimum_required(VERSION 3.14)
project(git_lazy LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(git_lazy
  lazy.cpp lazy.hpp main.cpp types.hpp
)

