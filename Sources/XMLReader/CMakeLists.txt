cmake_minimum_required(VERSION 3.6)

# Set the project name
project (XMLReader)

# Create a sources variable with a link to all cpp files to compile
set(SOURCES
	main.cpp
    Section.cpp
	Section.hpp
    XMLReader.cpp
	XMLReader.hpp
)

add_executable(XMLreader ${SOURCES})