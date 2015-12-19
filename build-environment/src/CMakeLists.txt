# This file was automatically generated! Do not modify...

cmake_minimum_required (VERSION 2.8)

default_source_scan("${CMAKE_SOURCE_DIR}/src/")

add_executable(arrays_d4b6b5eeea339da ${sources} ${headers}) 

make_project(arrays_d4b6b5eeea339da)

include_directories("${CMAKE_SOURCE_DIR}/include/")
include_directories("${CMAKE_SOURCE_DIR}/cli/include")

add_custom_command(TARGET arrays_d4b6b5eeea339da POST_BUILD 
	COMMAND "${CMAKE_COMMAND}" -E copy \"$<TARGET_FILE:arrays_d4b6b5eeea339da>\" "${CMAKE_SOURCE_DIR}/lib/" ) 