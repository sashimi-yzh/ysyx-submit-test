add_executable(TA ${TEST_HOME}/test.cpp)

target_link_libraries(TA 
    PUBLIC
        ls_assigner
)


