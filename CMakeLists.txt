cmake_minimum_required(VERSION 3.12)
project(zork)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(rapidxml-1.13)

add_executable(zork
        rapidxml-1.13/rapidxml.hpp
        rapidxml-1.13/rapidxml_iterators.hpp
        rapidxml-1.13/rapidxml_print.hpp
        rapidxml-1.13/rapidxml_utils.hpp
        Attack.cpp
        Attack.h
        container.cpp
        container.h
        creature.cpp
        creature.h
        header.h
        item.cpp
        item.h
        main.cpp
        main.h
        room.cpp
        room.h
        sample.txt.xml
        trigger.cpp
        trigger.h
        zork.h)
