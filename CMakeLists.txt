cmake_minimum_required(VERSION 3.12)

project(test)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

#
# GLFW
#

find_package(glfw3 3.3 QUIET)

if(NOT glfw3_FOUND)
	message(STATUS "Couldn't find glfw, fetching from github")

	FetchContent_Declare(
		glfw
		GIT_REPOSITORY "https://github.com/glfw/glfw.git"
		GIT_TAG 3.3-stable
	)

	FetchContent_GetProperties(glfw)

	if(NOT glfw_POPULATED)
		FetchContent_Populate(glfw)

		set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
		set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
		set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

		add_subdirectory(${glfw_SOURCE_DIR} ${glfw_BINARY_DIR})
	endif()
else()
    message(STATUS "Found glfw")
endif()

#
# Vulkan
#

set(VULKAN_ROOT_LOCATION "/Users/jadesjar/Source/" CACHE FILEPATH "Yuh")
set(VULKAN_SDK_VERSION "1.1.130.0" CACHE STRING "Yuh")

if(NOT VULKAN_ROOT_LOCATION AND NOT VULKAN_SDK_VERSION)
	message(STATUS "Error: VULKAN_ROOT_LOCATION or VULKAN_SDK_VERSION is not defined")
endif()

set(ENV{VULKAN_SDK} "${VULKAN_ROOT_LOCATION}/vulkansdk-macos-${VULKAN_SDK_VERSION}/macos")
set(ENV{VK_ICD_FILENAMES} "${VULKAN_SDK}/etc/vulkan/icd.d/MoltenVK_icd.json")
set(ENV{VK_LAYER_PATH} "${VULKAN_SDK}/etc/vulkan/explicit_layer.d")

find_package(vulkan REQUIRED)

add_executable(test source.cpp other.cpp)

target_link_libraries(test glfw Vulkan::Vulkan)
