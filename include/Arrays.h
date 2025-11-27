#pragma once
#include <vector>
#include <algorithm>

class Arrays {
public:
    /**
     * @brief Remove duplicates from sorted array in-place
     * 
     * Removes duplicates from a sorted array in-place and returns the number of unique elements.
     * The unique elements are placed at the beginning of the array.
     * 
     * @param nums Sorted array of integers (modified in-place)
     * @return Number of unique elements
     * @complexity Time: O(n), Space: O(1)
     */
    static int removeDuplicates(std::vector<int>& nums);

    /**
     * @brief Calculate maximum profit from buying and selling stock multiple times
     * 
     * Finds the maximum profit that can be achieved by buying and selling stock multiple times.
     * You can buy and sell on the same day, and can hold multiple stocks.
     * 
     * @param prices Array of stock prices for each day
     * @return Maximum profit achievable
     * @complexity Time: O(n), Space: O(1)
     */
    static int maxProfit(std::vector<int>& prices);

    /**
     * @brief Rotate array to the right by k steps
     * 
     * Rotates the array to the right by k steps in-place using the reverse algorithm.
     * 
     * @param nums Array to rotate (modified in-place)
     * @param k Number of steps to rotate right
     * @complexity Time: O(n), Space: O(1)
     */
    static void rotate(std::vector<int>& nums, int k);

    /**
     * @brief Check if array contains any duplicate elements
     * 
     * Determines if any value appears at least twice in the array.
     * 
     * @param nums Array of integers to check
     * @return true if duplicates exist, false otherwise
     * @complexity Time: O(n), Space: O(n)
     */
    static bool containsDuplicate(std::vector<int>& nums);

    /**
     * @brief Find the single number that appears only once
     * 
     * Finds the element that appears exactly once in an array where every other
     * element appears exactly twice. Uses XOR bitwise operation.
     * 
     * @param nums Array where all elements appear twice except one
     * @return The single number that appears only once
     * @complexity Time: O(n), Space: O(1)
     */
    static int singleNumber(std::vector<int>& nums);

    /**
     * @brief Find intersection of two arrays (respecting frequency)
     * 
     * Returns the intersection of two arrays, where each element in the result
     * appears as many times as it shows in both arrays.
     * 
     * @param nums1 First array
     * @param nums2 Second array
     * @return Vector containing the intersection elements
     * @complexity Time: O(n + m), Space: O(min(n, m))
     */
    static std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2);

    /**
     * @brief Increment a large integer represented as an array
     * 
     * Increments the large integer represented by the digits array by one.
     * The digits are stored such that the most significant digit is at the head.
     * 
     * @param digits Array representing a large integer (modified in-place)
     * @return Array representing the incremented integer
     * @complexity Time: O(n), Space: O(1) average, O(n) worst case (when carry propagates)
     */
    static std::vector<int> plusOne(std::vector<int>& digits);

    /**
     * @brief Move all zeros to the end while maintaining relative order
     * 
     * Moves all 0's to the end of the array while maintaining the relative order
     * of the non-zero elements. Performed in-place.
     * 
     * @param nums Array to modify (modified in-place)
     * @complexity Time: O(n), Space: O(1)
     */
    static void moveZeroes(std::vector<int>& nums);

    /**
     * @brief Find two numbers that add up to target
     * 
     * Returns indices of the two numbers such that they add up to target.
     * Assumes exactly one solution exists and cannot use the same element twice.
     * 
     * @param nums Array of integers
     * @param target Target sum
     * @return Vector containing the two indices [i, j] where nums[i] + nums[j] == target
     * @complexity Time: O(n), Space: O(n)
     */
    static std::vector<int> twoSum(std::vector<int>& nums, int target);

    /**
     * @brief Validate a 9x9 Sudoku board
     * 
     * Determines if a 9x9 Sudoku board is valid. Only filled cells need validation.
     * A valid board must satisfy: no duplicates in rows, columns, or 3x3 boxes.
     * 
     * @param board 9x9 Sudoku board ('.' represents empty cell)
     * @return true if board is valid, false otherwise
     * @complexity Time: O(1) - fixed 81 cells, Space: O(1) - fixed size arrays
     */
    static bool isValidSudoku(std::vector<std::vector<char>>& board);

    /**
     * @brief Rotate a 2D matrix 90 degrees clockwise
     * 
     * Rotates an n x n 2D matrix by 90 degrees clockwise in-place.
     * Uses transpose and reverse operations.
     * 
     * @param matrix n x n matrix to rotate (modified in-place)
     * @complexity Time: O(n²), Space: O(1)
     */
    static void rotateImage(std::vector<std::vector<int>>& matrix);
};