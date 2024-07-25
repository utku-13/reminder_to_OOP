cmake_minimum_required(VERSION 3.27)
project(reminder_to_OOP)

set(CMAKE_CXX_STANDARD 23)

add_executable(reminder_to_OOP main.cpp
        movie.h
        movie.cpp
        movies.cpp
        movies.h)
