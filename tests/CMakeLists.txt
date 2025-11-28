include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

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