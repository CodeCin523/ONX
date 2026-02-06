add_executable(test_stack mem/test_stack.c)
target_link_libraries(
    test_stack PRIVATE
    Shemodogan::SHD
)