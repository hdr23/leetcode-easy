#pragma once
#include <string>
#include <vector>
#include <cstdint>

class OtherProblems {
public:
    /**
     * @brief Count the number of 1 bits in an unsigned integer (Hamming Weight)
     * 
     * Returns the number of '1' bits in the binary representation of an unsigned integer.
     * 
     * @param n Unsigned integer
     * @return Number of 1 bits
     * @complexity Time: O(1) - at most 32 iterations, Space: O(1)
     * @difficulty Easy
     * @see https://leetcode.com/problems/number-of-1-bits/
     */
    static int hammingWeight(uint32_t n);

    /**
     * @brief Reverse bits of an unsigned 32-bit integer
     * 
     * Reverses the bits of a given 32-bit unsigned integer.
     * 
     * @param n Unsigned 32-bit integer
     * @return Integer with reversed bits
     * @complexity Time: O(1) - 32 iterations, Space: O(1)
     * @difficulty Easy
     * @see https://leetcode.com/problems/reverse-bits/
     */
    static uint32_t reverseBits(uint32_t n);

    /**
     * @brief Find the missing number in an array
     * 
     * Given an array containing n distinct numbers taken from 0, 1, 2, ..., n,
     * find the one that is missing from the array.
     * 
     * @param nums Array containing n distinct numbers from [0, n]
     * @return The missing number
     * @complexity Time: O(n), Space: O(1)
     * @difficulty Easy
     * @see https://leetcode.com/problems/missing-number/
     */
    static int missingNumber(std::vector<int>& nums);

    /**
     * @brief Check if parentheses string is valid
     * 
     * Determines if a string containing only '(', ')', '{', '}', '[' and ']'
     * is valid. A string is valid if:
     * - Open brackets must be closed by the same type of brackets
     * - Open brackets must be closed in the correct order
     * 
     * @param s String containing only parentheses characters
     * @return true if valid, false otherwise
     * @complexity Time: O(n), Space: O(n)
     * @difficulty Easy
     * @see https://leetcode.com/problems/valid-parentheses/
     */
    static bool isValid(std::string s);

    /**
     * @brief Count ways to climb stairs
     * 
     * You are climbing a staircase. It takes n steps to reach the top.
     * Each time you can either climb 1 or 2 steps. In how many distinct ways
     * can you climb to the top?
     * 
     * @param n Number of steps
     * @return Number of distinct ways to climb
     * @complexity Time: O(n), Space: O(1)
     * @difficulty Easy
     * @see https://leetcode.com/problems/climbing-stairs/
     */
    static int climbStairs(int n);
};

