file(GLOB_RECURSE SOURCES "${LS_ASSIGNER_HOME}/*.cpp")

file(GLOB_RECURSE HEADER_FILES "${LS_ASSIGNER_HOME}/*.h")

set(HEADER_DIRS "")
foreach(HEADER_FILE ${HEADER_FILES})
    get_filename_component(HEADER_DIR ${HEADER_FILE} DIRECTORY)
    list(APPEND HEADER_DIRS ${HEADER_DIR})
endforeach()

list(REMOVE_DUPLICATES HEADER_DIRS)

add_library(ls_assigner
    ${SOURCES}
)

target_link_libraries(ls_assigner 
    PUBLIC
        OpenMP::OpenMP_CXX
)

target_include_directories(ls_assigner 
    PUBLIC 
        ${HEADER_DIRS}
)