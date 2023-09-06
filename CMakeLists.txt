# The following lines of boilerplate have to be in your project's
# CMakeLists in this exact order for cmake to work correctly
cmake_minimum_required(VERSION 3.5)

set (CMAKE_CXX_STANDARD 14)

# LOGL_NONE    0
# LOGL_ERROR   2
# LOGL_WARNING 3
# LOGL_INFO    4
# LOGL_DEBUG   5
# LOGL_TRACE   6
add_compile_definitions(MAXLOGLEVEL=6)

include($ENV{IDF_PATH}/tools/cmake/project.cmake)
project(app-template)
