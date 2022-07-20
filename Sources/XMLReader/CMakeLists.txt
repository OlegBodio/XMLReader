cmake_minimum_required(VERSION 3.6)

# Set the project name
project (XMLReader)


# Creating library
add_library(Section_lib STATIC
	libs/Section_lib/Section.cpp
	)
	
target_include_directories(Section_lib 
	PUBLIC
		libs/Section_lib
)
	
	

# Create a sources variable with a link to all cpp files to compile
set(SOURCES
    main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME}
	PRIVATE
		Section_lib
)