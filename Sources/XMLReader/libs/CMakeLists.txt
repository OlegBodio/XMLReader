# Creating library
add_library(Section_lib STATIC
	Section_lib/Section.cpp
	)
	
target_include_directories(Section_lib 
	PUBLIC
		Section_lib
)
	