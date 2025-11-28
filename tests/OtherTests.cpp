#include <gtest/gtest.h>
#include "OtherProblems.h"
#include <cstdint>

// Test for hammingWeight (Number of 1 Bits)
TEST(OtherTests, HammingWeight) {
    // Test case 1: 11 (binary: 1011) has 3 ones
    EXPECT_EQ(OtherProblems::hammingWeight(11), 3);
    
    // Test case 2: 128 (binary: 10000000) has 1 one
    EXPECT_EQ(OtherProblems::hammingWeight(128), 1);
    
    // Test case 3: 4294967293 (binary: 11111111111111111111111111111101) has 31 ones
    EXPECT_EQ(OtherProblems::hammingWeight(4294967293), 31);
    
    // Test case 4: 0 has 0 ones
    EXPECT_EQ(OtherProblems::hammingWeight(0), 0);
}

// Test for reverseBits
TEST(OtherTests, ReverseBits) {
    // Test case 1: 43261596 (binary: 00000010100101000001111010011100)
    // Reversed:    964176192 (binary: 00111001011110000010100101000000)
    EXPECT_EQ(OtherProblems::reverseBits(43261596), 964176192);
    
    // Test case 2: 4294967293 (binary: 11111111111111111111111111111101)
    // Reversed:    3221225471 (binary: 10111111111111111111111111111111)
    EXPECT_EQ(OtherProblems::reverseBits(4294967293), 3221225471);
    
    // Test case 3: 0 reversed is still 0
    EXPECT_EQ(OtherProblems::reverseBits(0), 0);
}

// Test for missingNumber
TEST(OtherTests, MissingNumber) {
    // Test case 1: [3, 0, 1] - missing 2
    std::vector<int> nums1 = {3, 0, 1};
    EXPECT_EQ(OtherProblems::missingNumber(nums1), 2);
    
    // Test case 2: [0, 1] - missing 2
    std::vector<int> nums2 = {0, 1};
    EXPECT_EQ(OtherProblems::missingNumber(nums2), 2);
    
    // Test case 3: [9, 6, 4, 2, 3, 5, 7, 0, 1] - missing 8
    std::vector<int> nums3 = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    EXPECT_EQ(OtherProblems::missingNumber(nums3), 8);
    
    // Test case 4: [0] - missing 1
    std::vector<int> nums4 = {0};
    EXPECT_EQ(OtherProblems::missingNumber(nums4), 1);
}

// Test for isValid (Valid Parentheses)
TEST(OtherTests, ValidParentheses) {
    // Test case 1: "()" is valid
    EXPECT_TRUE(OtherProblems::isValid("()"));
    
    // Test case 2: "()[]{}" is valid
    EXPECT_TRUE(OtherProblems::isValid("()[]{}"));
    
    // Test case 3: "(]" is invalid
    EXPECT_FALSE(OtherProblems::isValid("(]"));
    
    // Test case 4: "([)]" is invalid
    EXPECT_FALSE(OtherProblems::isValid("([)]"));
    
    // Test case 5: "{[]}" is valid
    EXPECT_TRUE(OtherProblems::isValid("{[]}"));
    
    // Test case 6: "(" is invalid (unclosed)
    EXPECT_FALSE(OtherProblems::isValid("("));
    
    // Test case 7: ")" is invalid (no opening)
    EXPECT_FALSE(OtherProblems::isValid(")"));
    
    // Test case 8: Empty string is valid
    EXPECT_TRUE(OtherProblems::isValid(""));
}

// Test for climbStairs
TEST(OtherTests, ClimbStairs) {
    // Test case 1: n = 2, ways = 2 (1+1, 2)
    EXPECT_EQ(OtherProblems::climbStairs(2), 2);
    
    // Test case 2: n = 3, ways = 3 (1+1+1, 1+2, 2+1)
    EXPECT_EQ(OtherProblems::climbStairs(3), 3);
    
    // Test case 3: n = 4, ways = 5
    EXPECT_EQ(OtherProblems::climbStairs(4), 5);
    
    // Test case 4: n = 5, ways = 8
    EXPECT_EQ(OtherProblems::climbStairs(5), 8);
    
    // Test case 5: n = 1, ways = 1
    EXPECT_EQ(OtherProblems::climbStairs(1), 1);
    
    // Test case 6: n = 10, ways = 89 (Fibonacci sequence)
    EXPECT_EQ(OtherProblems::climbStairs(10), 89);
}

