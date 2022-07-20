cmake_minimum_required(VERSION 3.6)

set(Section_lib_dir 
	../libs/Section_lib)

# Set the project name
project (XMLReader)	

# Create a sources variable with a link to all cpp files to compile
set(SOURCES
    main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME}
	PRIVATE
		Section_lib
)