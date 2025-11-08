cmake_minimum_required(VERSION 3.10)
project(MyBuddy)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#---------------------------------------------Compiler Flags------------------------------------------------
# Base compiler flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -Wextra ")
message("Current flags: ${CMAKE_CXX_FLAGS}")
#set(CMAKE_BUILD_TYPE Debug)

# Append Unit test build
if (UNIT_TEST)
    message(STATUS "Unit test enabled")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}-DMMC_UNITEST")
endif()
#---------------------------------------------Find Dependency Packages------------------------------------
# Find ncurses
find_package(Curses REQUIRED)
#Print ncurses info
message(STATUS "CURSES_FOUND: ${CURSES_FOUND}")
message(STATUS "CURSES_INCLUDE_DIR: ${CURSES_INCLUDE_DIR}")
message(STATUS "CURSES_LIBRARIES: ${CURSES_LIBRARIES}")
include_directories(${CURSES_INCLUDE_DIR})

#--------------------------------------------Project Specific---------------------------------------------
# Define paths
set(LOCAL_PATH "./")
set(LOCAL_BUILD_PATH "${LOCAL_PATH}/Build")
set(LOCAL_APP_PATH "${LOCAL_PATH}/App")
set(LOCAL_CORE_PATH "${LOCAL_PATH}/Core")

# Set where executables go
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${LOCAL_BUILD_PATH}/../bin)
# Set where libraries go
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${LOCAL_BUILD_PATH}/../lib)   # shared libraries (.so)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${LOCAL_BUILD_PATH}/../lib)   # static libraries (.a)

# Include project directories
include_directories(
    ${LOCAL_APP_PATH}/inc
    ${LOCAL_CORE_PATH}/inc
)

# Source files for core
set(APP_CORE
    ${LOCAL_CORE_PATH}/database/Database.cpp
)

# Source files for application
set(APP_SRC
    ${LOCAL_APP_PATH}/src/MyBuddy.cpp
)

# Create libAppCore library
add_library(libAppCore STATIC ${APP_CORE})
#target_link_libraries(libAppCore pthread rt)

# Add executable
add_executable(MyBuddy ${APP_SRC})
# Link libraries to the executable
target_link_libraries(MyBuddy libAppCore ${CURSES_LIBRARIES})



