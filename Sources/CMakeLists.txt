cmake_minimum_required (VERSION 3.6)

project(Solution)

set(main_dir
	XMLReader/main)

set(libs_dir
	XMLReader/libs)

# Add sub directories
add_subdirectory(${main_dir})
add_subdirectory(${libs_dir})
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${main_dir})
