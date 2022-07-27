cmake_minimum_required(VERSION 3.16)
project("Solution")
set(CMAKE_CXX_STANDARD 17)

set(MAIN_SOURCE "${PROJECT_SOURCE_DIR}/source/main")
set(MODULE_SOURCE "${PROJECT_SOURCE_DIR}/source/module")
set(LIBS "${PROJECT_SOURCE_DIR}/externals")
cmake_minimum_required (VERSION 3.6)

# pybind11
include(FetchContent)
FetchContent_Declare(
	pybind11
	GIT_REPOSITORY https://github.com/pybind/pybind11.git
	GIT_TAG        v2.6.2
	GIT_SHALLOW    TRUE
)
FetchContent_MakeAvailable(pybind11)


# module
pybind11_add_module (
    section_py_module 
    ${MODULE_SOURCE}/sectionPy.cpp
)

target_include_directories (
    section_py_module 
    PRIVATE ${MODULE_SOURCE}
)

# main
add_executable (
    main
    ${MAIN_SOURCE}/main.cpp
)

#add_SectionLib
add_library(section_lib STATIC
	source/libs/sectionLib/section.cpp
	)
	
target_include_directories(section_lib 
	PUBLIC
		section_lib
)

target_include_directories (
    main 
    PRIVATE ${MAIN_SOURCE}
    PRIVATE ${MODULE_SOURCE}
)

target_link_libraries(
    main
    PRIVATE pybind11::embed
	PRIVATE section_lib
)