# Copyright (C) 2026 Mykyta Polishyk
# This project is licensed under the MIT License.
# See the LICENSE file for details.

cmake_minimum_required(VERSION 3.12)
project(MatrixShuffle LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O2")

# Targets
file(GLOB SOURCES "Sources/*.cpp")


# Adding libraries
# wxWidgets
find_package(wxWidgets REQUIRED COMPONENTS core base gl)
if(wxWidgets_FOUND)
    include(${wxWidgets_USE_FILE})
endif()

# Boost
find_package(Boost REQUIRED COMPONENTS system)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
endif()

# Executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Linking
target_link_libraries(${PROJECT_NAME} PRIVATE ${wxWidgets_LIBRARIES} Boost::system)