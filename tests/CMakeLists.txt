# Use local googletest from libs folder
add_subdirectory(../libs/googletest-1.14.0 ${CMAKE_BINARY_DIR}/googletest)

# ArrayProblems Tests
add_executable(ArrayTests ArrayTests.cpp)
target_link_libraries(ArrayTests LeetCodeLib GTest::gtest_main)
add_test(NAME ArrayTests COMMAND ArrayTests)

# StringProblems Tests
add_executable(StringTests StringTests.cpp)
target_link_libraries(StringTests LeetCodeLib GTest::gtest_main)
add_test(NAME StringTests COMMAND StringTests)

# LinkedListProblems Tests
add_executable(LinkedListTests LinkedListTests.cpp)
target_link_libraries(LinkedListTests LeetCodeLib GTest::gtest_main)
add_test(NAME LinkedListTests COMMAND LinkedListTests)

# TreeProblems Tests
add_executable(TreeTests TreeTests.cpp)
target_link_libraries(TreeTests LeetCodeLib GTest::gtest_main)
add_test(NAME TreeTests COMMAND TreeTests)

# OtherProblems Tests
add_executable(OtherTests OtherTests.cpp)
target_link_libraries(OtherTests LeetCodeLib GTest::gtest_main)
add_test(NAME OtherTests COMMAND OtherTests)