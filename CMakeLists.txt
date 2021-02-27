
cmake_minimum_required(VERSION 3.17.0 FATAL_ERROR)

set(CPPOTIO_VERSION_MAJOR "0")
set(CPPOTIO_VERSION_MINOR "14")
set(CPPOTIO_VERSION_PATCH "0")
set(CPPOTIO_VERSION ${CPPOTIO_VERSION_MAJOR}.${CPPOTIO_VERSION_MINOR}.${CPPOTIO_VERSION_PATCH})

set(CPPOTIO_AUTHOR "Contributors to the OpenTimelineIO project")
set(CPPOTIO_AUTHOR_EMAIL "opentimelineio@pixar.com")
set(CPPOTIO_LICENSE "Modified Apache 2.0 License")

project(cpp_opentimelineio VERSION ${CPPOTIO_VERSION} LANGUAGES CXX C)

#------------------------------------------------------------------------------
# Global language settings

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#------------------------------------------------------------------------------
# Build options
option(CPPOTIO_INSTALL "Install the c bindings" ON)
option(CPPOTIO_SHARED_LIBS "Build shared if ON, static if OFF" ON)
option(CPPOTIO_AUTOMATIC_SUBMODULES "Fetch submodules automatically" ON)

if (CPPOTIO_SHARED_LIBS)
    message(INFO, "Building shared libs.")
    set(CPPOTIO_SHARED_OR_STATIC_LIB "SHARED")
else ()
    message(INFO, "Building static libs.")
    set(CPPOTIO_SHARED_OR_STATIC_LIB "STATIC")
endif ()

#------------------------------------------------------------------------------
# Fetch or refresh submodules if requested

find_package(Git QUIET)
if (GIT_FOUND)
    message(INFO, "Checking git repo is available:")
    execute_process(
            # the following command returns true if cwd is in the repo
            COMMAND ${GIT_EXECUTABLE} rev-parse --is-inside-work-tree
            WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
            RESULT_VARIABLE IN_A_GIT_REPO_RETCODE
    )
endif ()

if (GIT_FOUND AND IN_A_GIT_REPO_RETCODE EQUAL 0)
    # you might want to turn this off if you're working in one of the submodules
    # or trying it out with a different version of the submodule
    option(GIT_UPDATE_SUBMODULES "Update submodules each build" ON)
    if (GIT_UPDATE_SUBMODULES)
        message(
                STATUS "root: Updating git submodules to make sure they are up to date"
        )
        execute_process(
                COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
                RESULT_VARIABLE GIT_UPDATE_SUBMODULES_RESULT
        )
        if (NOT GIT_UPDATE_SUBMODULES_RESULT EQUAL "0")
            message(
                    FATAL_ERROR
                    "git submodule update --init --recursive failed with \
                    ${GIT_UPDATE_SUBMODULES_RESULT}"
            )
        endif ()
    endif ()
endif ()

#------------------------------------------------------------------------------
# Build the dependencies and components

set(OTIO_PYTHON_INSTALL OFF CACHE BOOL "") # Disable building of python bindings
# Do not install any of the original bindings/libs
set(OTIO_CXX_INSTALL OFF CACHE BOOL "")
set(OTIO_DEPENDENCIES_INSTALL OFF CACHE BOOL "")
set(OTIO_INSTALL_COMMANDLINE_TOOLS OFF CACHE BOOL "")
set(OTIO_SHARED_LIBS CPPOTIO_SHARED_LIBS CACHE STRING "") # build otio as a static lib

enable_testing()

add_subdirectory(OpenTimelineIO)
add_subdirectory(src)
add_subdirectory(tests)
