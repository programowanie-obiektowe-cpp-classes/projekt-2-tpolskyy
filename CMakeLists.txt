cmake_minimum_required(VERSION 3.14)
project(cpp-project CXX)

# Dodaj katalog z nagłówkami TinyXML
include_directories("${CMAKE_SOURCE_DIR}/include")

# Dodaj pliki źródłowe projektu
set(SOURCE_FILES 
    src/main.cpp
    src/Microwave.cpp
    src/Food.cpp
    src/tinyxml2.cpp 
)
set(HPP_FILES 
    include/Microwave.hpp
    include/Food.hpp
    include/tinyxml2.h  
)
set(xml_FILES 
    xml/dishes.xml
)
add_executable(cpp-project ${SOURCE_FILES} ${HPP_FILES} ${xml_FILES})


set_target_properties(cpp-project PROPERTIES CXX_STANDARD 23)