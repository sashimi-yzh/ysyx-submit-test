cmake_minimum_required(VERSION 3.10)
project(LSAssigner)

set(CMAKE_CXX_STANDARD 20)

set(LS_ASSIGNER_HOME ${PROJECT_SOURCE_DIR})

find_package(OpenMP REQUIRED)
if (OPENMP_FOUND)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
endif()

set(LS_ASSIGNER_HOME ${PROJECT_SOURCE_DIR}/ls_assigner)
set(TEST_HOME ${PROJECT_SOURCE_DIR}/test)

add_subdirectory(${LS_ASSIGNER_HOME})
add_subdirectory(${TEST_HOME})