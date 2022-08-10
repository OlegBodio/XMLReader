cmake_minimum_required(VERSION 3.16)
project("Solution")
set(CMAKE_CXX_STANDARD 17)

set(MAIN_SOURCE "${PROJECT_SOURCE_DIR}/source/main")
set(MODULE_SOURCE "${PROJECT_SOURCE_DIR}/source/module")
set(LIBS_SOURCE"${PROJECT_SOURCE_DIR}/source/libs")
set(resmgr_lib_SOURCE "${PROJECT_SOURCE_DIR}/source/libs/resmgr_lib")

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

# section module
pybind11_add_module (
    section_py_module 
    ${MODULE_SOURCE}/SectionPy/sectionPy.cpp
	${MODULE_SOURCE}/SectionPy/sectionPy.hpp
	${MODULE_SOURCE}/SectionPy/ResMgrPy.cpp
	${MODULE_SOURCE}/SectionPy/ResMgrPy.hpp
)

target_include_directories (
    section_py_module 
    PRIVATE ${MODULE_SOURCE}/SectionPy
	PRIVATE ${LIBS_SOURCE}
)

target_link_libraries(
    section_py_module
	PRIVATE resmgr_lib
)

# main
add_executable (
    main
    ${MAIN_SOURCE}/main.cpp
)

#add_SectionLib
add_library(resmgr_lib STATIC
	${resmgr_lib_SOURCE}/section.cpp
	${resmgr_lib_SOURCE}/section.hpp
	${resmgr_lib_SOURCE}/resmgr.cpp
	${resmgr_lib_SOURCE}/resmgr.hpp
	)
	
target_include_directories(resmgr_lib 
	PUBLIC
		source/libs/resmgr_lib
)

target_include_directories (
    main 
    PRIVATE ${MAIN_SOURCE}
    PRIVATE ${MODULE_SOURCE}/SectionPy
	PRIVATE ${MODULE_SOURCE}/ResMgrPy
	PRIVATE ${LIBS_SOURCE}
)

target_link_libraries(
    main
    PRIVATE pybind11::embed
	PRIVATE resmgr_lib
)

add_dependencies(
	main 
	section_py_module
)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT main)