# M.I.T. License - http://opensource.org/licenses/mit-license.php/
# 
# Copyright (c) 2012 Christoph Husse
# 
# Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated 
# documentation files (the "Software"), to deal in the Software without restriction, including without limitation 
# the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, 
# and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
# 
# The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
# 
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED 
# TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL 
# THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF 
# CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER 
# DEALINGS IN THE SOFTWARE.
# 
# 
# This file only provides convenient macros. It requires a CMake_Project_Config.txt in the same directory,
# where you would perform the project specific actions required to generate a build system.
# 
# MacOS is currently not supported, since I don't have access to a Mac! Shouldn't be too hard to add though.

cmake_minimum_required (VERSION 2.8)
 
 
 # enables precompiled header for given target (currently supported for MSVC only, feel free to add more)
MACRO(USE_PCH target)
	if (MSVC)
	   set_target_properties(${target} PROPERTIES COMPILE_FLAGS "/Yustdafx.h")
	   set_source_files_properties(stdafx.cpp PROPERTIES COMPILE_FLAGS "/Ycstdafx.h")
	else()
		message(WARNING "Chosen target build system does not support precompiled headers.")
	endif(MSVC)
ENDMACRO(USE_PCH)

# internal macro for default_source_scan() 
macro(scan_sources root_name dir_name out_list extenstions)

	get_filename_component(dir_name "${dir_name}" REALPATH)
	
	FOREACH (ext IN ITEMS ${extenstions})
		FILE (GLOB_RECURSE new_list "${dir_name}*.${ext}")
		FOREACH (src IN ITEMS ${new_list})
			get_filename_component(fileDir "${src}" PATH)
			
			# add IDE file group based on relative path to ${dir_name}
			STRING (REGEX REPLACE "^${dir_name}" "${root_name}\\\\" rel_dir "${fileDir}/")
			STRING (REGEX REPLACE "[/]+" "\\\\" rel_dir "${rel_dir}")
			SOURCE_GROUP ("${rel_dir}" FILES "${src}")
			
			LIST(APPEND ${out_list} "${src}")
		ENDFOREACH (src)
	ENDFOREACH(ext)
endmacro(scan_sources)

macro(postbuild_copy_file target src dst)
	get_filename_component(src2 "${src}" REALPATH)
	get_filename_component(dst2 "${dst}" REALPATH)

	add_custom_command(TARGET ${target} POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy ARGS "${src2}" "${dst2}")
endmacro(postbuild_copy_file)

# scans the given directory ${rootDir} recursively for C++ header/source files
# and adds them to the current compilation stage. The relative directory tree
# within the scan directory is kept for all IDE's supporting some kind of folders.
macro(default_source_scan rootDir)
	scan_sources("Header Files" "${rootDir}" headers "${INC_EXTENSIONS}")
	scan_sources("Source Files" "${rootDir}" sources "${SRC_EXTENSIONS}")
endmacro(default_source_scan)

# create a new project with name ${project_name}
macro(make_project project_name)
	project(${project_name})
	 
	# get directory difference between current dir and root dir
	STRING (REGEX REPLACE "^${CMAKE_SOURCE_DIR}" "" TARGET_PARTIAL_PATH "${CMAKE_CURRENT_SOURCE_DIR}/")
		
	set_target_properties(${project_name}
		PROPERTIES
			ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib/${TARGET_PARTIAL_PATH}"
			ARCHIVE_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/lib/${TARGET_PARTIAL_PATH}"
			ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/lib/${TARGET_PARTIAL_PATH}"
			LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/${TARGET_PARTIAL_PATH}"
			LIBRARY_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/bin/${TARGET_PARTIAL_PATH}"
			LIBRARY_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/bin/${TARGET_PARTIAL_PATH}"
			RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/${TARGET_PARTIAL_PATH}"
			RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/bin/${TARGET_PARTIAL_PATH}"
			RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/bin/${TARGET_PARTIAL_PATH}"
	)
	
	if (MSVC)
		set_target_properties(${project_name} PROPERTIES
			LINK_FLAGS_DEBUG "/SUBSYSTEM:CONSOLE"
			LINK_FLAGS_RELEASE "/SUBSYSTEM:CONSOLE")
	endif(MSVC)
	
endmacro(make_project)

# shows a cmake configuration entry with a description and stores the user selected path
# in a given variable. For instance, 
#         require_special_directory(DIRECTX_ROOT "Path to the root directory of your DirectX SDK.")
# will ask for the DirectX root directory and store the full canonical path in a variable DIRECTX_ROOT.
macro(require_special_directory varName description)
	set(${varName} CACHE PATH "${description}")
	get_filename_component(${varName} "${${varName}}" REALPATH)
endmacro()

# Adds DirectX dependencies to a given target ${target_name}, requiring all given DX libraries ${names}
# as a semicolon separated list (i.e. "xinput.lib;d3dx11.lib;d3d11.lib"). It does nothing on
# platforms other than Microsoft Windows. It automatically scans for those libraries, respecting
# 32/64-bit, depending only on a user provided path to the DirectX SDK root directory.
macro(link_dxlibs target_name names)

	if(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
		require_special_directory(DIRECTX_ROOT "Path to the root directory of your DirectX SDK.")

		foreach(name IN ITEMS ${names})
			IF(${IS64BIT})
				link_external_library(DIRECTX_LIB_${name} "${DIRECTX_ROOT}/lib/x64" ${name})
			ELSE()
				link_external_library(DIRECTX_LIB_${name} "${DIRECTX_ROOT}/lib/x86" ${name})
			ENDIF()
			
			target_link_libraries(${target_name} "${DIRECTX_LIB_${name}}")
		endforeach(name)
	endif()
endmacro(link_dxlibs)

# tries to find a certain library in directory ${dir_name} while trying
# a semicolon separated list of aliases (you can also specify only one potential name).
# If it can find the library, a variable named ${var_prefix} is filled with a
# canonical path to it. Otherwise, an invalid path named "${var_prefix}-NOTFOUND" is stored.
# Further, if the library can not be found, CMake will report this issue and prevent
# generation until it is resolved.
macro(link_external_library var_prefix dir_name lib_name_list)
	find_library(${var_prefix} NAMES ${lib_name_list} PATHS ${dir_name} NO_DEFAULT_PATH)
	
	if("${var_prefix}-NOTFOUND" STREQUAL "${${var_prefix}}")
		message(WARNING "A library with alias(es) \"${lib_name_list}\" could not be found in directory \"${dir_name}\"!")
	elseif(NOT EXISTS "${${var_prefix}}")
		message(WARNING "A library with alias(es) \"${lib_name_list}\" could not be found at path \"${${var_prefix}}\"!")
	endif()
	
	set(LIBS ${LIBS} ${var_prefix})
endmacro(link_external_library)

# allows you to put a project into a solution-subfolder in visual studio.
# Seems to be not supported for VS2012 in CMake 2.8.9 though.
MACRO(SET_VISUAL_STUDIO_FOLDER project_name folder)
	IF(MSVC)
		set(USING_VISUAL_STUDIO_EXPRESS CACHE "Are you targeting an express version of visual studio?")

		IF(NOT ${USING_VISUAL_STUDIO_EXPRESS})
			SET_PROPERTY(GLOBAL PROPERTY USE_FOLDERS ON)
			SET_PROPERTY(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "")

			IF(NOT ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION} LESS 2.8)
				SET_PROPERTY(TARGET "${project_name}" PROPERTY FOLDER "${folder}")
			ENDIF()
		ENDIF()
		ELSE()
			SET_PROPERTY(GLOBAL PROPERTY USE_FOLDERS OFF)
		ENDIF()
	ENDIF()
ENDMACRO(SET_VISUAL_STUDIO_FOLDER)

# adds a post-build action (if supported by the target build system) which copies the 
# generated archive of a project ${projectName} to a given target directory ${targetDir}.
macro(postbuild_copy_archive projectName targetDir)
	IF(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
		get_target_property(tmpPath ${projectName} ARCHIVE_OUTPUT_DIRECTORY)
		file(MAKE_DIRECTORY "${targetDir}")
		postbuild_copy_file(${projectName} "${tmpPath}/${projectName}.lib" "${targetDir}/${projectName}.lib")
	ENDIF()
endmacro(postbuild_copy_archive)

# adds a post-build action (if supported by the target build system) which copies the 
# compiled library of a project ${projectName} to a given target directory ${targetDir}.
macro(postbuild_copy_library projectName targetDir)
	get_target_property(tmpPath ${projectName} LIBRARY_OUTPUT_DIRECTORY)
	file(MAKE_DIRECTORY "${targetDir}")
	IF(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
		postbuild_copy_file(${projectName} "${tmpPath}/${projectName}.dll" "${targetDir}/${projectName}.dll")
	ELSE()
		postbuild_copy_file(${projectName} "${tmpPath}/${projectName}.so" "${targetDir}/${projectName}.so")
	ENDIF()
endmacro(postbuild_copy_library)

# adds a post-build action (if supported by the target build system) which copies the 
# compiled binary of a project ${projectName} to a given target directory ${targetDir}.
macro(postbuild_copy_runtime projectName targetDir)
	get_target_property(tmpPath ${projectName} RUNTIME_OUTPUT_DIRECTORY)
	file(MAKE_DIRECTORY "${targetDir}")
	IF(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
		postbuild_copy_file(${projectName} "${tmpPath}/${projectName}.exe" "${targetDir}/${projectName}.exe")
	ELSE()
		postbuild_copy_file(${projectName} "${tmpPath}/${projectName}" "${targetDir}/${projectName}")
	ENDIF()
endmacro(postbuild_copy_runtime)

# allows user to choose between static and dynamic linkage to visual studio runtime.
macro(configure_msvc_runtime)
	if(MSVC)
		if("${MSVC_STATIC_RUNTIME}" STREQUAL "")
			set(MSVC_STATIC_RUNTIME CACHE BOOL "Statically link with Visual Studio runtime.")
		endif()
		
		set(VARIABLES
				CMAKE_C_FLAGS_DEBUG
				CMAKE_C_FLAGS_MINSIZEREL
				CMAKE_C_FLAGS_RELEASE
				CMAKE_C_FLAGS_RELWITHDEBINFO
				CMAKE_CXX_FLAGS_DEBUG
				CMAKE_CXX_FLAGS_MINSIZEREL
				CMAKE_CXX_FLAGS_RELEASE
				CMAKE_CXX_FLAGS_RELWITHDEBINFO
		)
		
		if(${MSVC_STATIC_RUNTIME})
			foreach(variable ${variables})
				if(${variable} MATCHES "/MD")
					string(REGEX REPLACE "/MD" "/MT" ${variable} "${${variable}}")
				endif()
			endforeach()
		else()		
			foreach(variable ${variables})
				if(${variable} MATCHES "/MT")
					string(REGEX REPLACE "/MT" "/MD" ${variable} "${${variable}}")
				endif()
			endforeach()
		endif()
	endif()
endmacro()

# file extensions of files you want to be added to the "Header Files" group.
set(INC_EXTENSIONS h;hpp;enum;)

# file extensions of files you want to be added to the "Source Files" group
set(SRC_EXTENSIONS c;cpp;cxx;)


# just copy CMake's default compiler flags into our variables
set(DEFAULT_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
set(DEFAULT_CXX_RELEASE_FLAGS "${CMAKE_CXX_FLAGS_RELEASE}")
set(DEFAULT_CXX_DEBUG_FLAGS "${CMAKE_CXX_FLAGS_DEBUG}")
set(DEFAULT_CXX_RELWITHDEBINFO_FLAGS "${CMAKE_CXX_FLAGS_RELWITHDEBINFO}")
set(DEFAULT_CXX_MINSIZEREL_FLAGS "${CMAKE_CXX_FLAGS_MINSIZEREL}")


# include project specific stuff, otherwise this file does nothing!

include(CMake_Project_Config.txt)
