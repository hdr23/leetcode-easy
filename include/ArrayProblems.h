#pragma once
#include <vector>
#include <algorithm>

class ArrayProblems {
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
     * @difficulty Easy
     * @see https://leetcode.com/problems/remove-duplicates-from-sorted-array/
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
     * @difficulty Easy
     * @see https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
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
     * @difficulty Medium
     * @see https://leetcode.com/problems/rotate-array/
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
     * @difficulty Easy
     * @see https://leetcode.com/problems/contains-duplicate/
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
     * @difficulty Easy
     * @see https://leetcode.com/problems/single-number/
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
     * @difficulty Easy
     * @see https://leetcode.com/problems/intersection-of-two-arrays-ii/
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
     * @difficulty Easy
     * @see https://leetcode.com/problems/plus-one/
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
     * @difficulty Easy
     * @see https://leetcode.com/problems/move-zeroes/
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
     * @difficulty Easy
     * @see https://leetcode.com/problems/two-sum/
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
     * @difficulty Medium
     * @see https://leetcode.com/problems/valid-sudoku/
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
     * @difficulty Medium
     * @see https://leetcode.com/problems/rotate-image/
     */
    static void rotateImage(std::vector<std::vector<int>>& matrix);

    /**
     * @brief Find maximum sum of contiguous subarray (Kadane's algorithm)
     * 
     * Finds the contiguous subarray (containing at least one number) which has
     * the largest sum and returns its sum.
     * 
     * @param nums Array of integers
     * @return Maximum sum of contiguous subarray
     * @complexity Time: O(n), Space: O(1)
     * @difficulty Easy
     * @see https://leetcode.com/problems/maximum-subarray/
     */
    static int maxSubArray(std::vector<int>& nums);

    /**
     * @brief Product of array except self
     * 
     * Returns an array answer such that answer[i] is equal to the product of
     * all the elements of nums except nums[i]. Must run in O(n) time and
     * without using division operator.
     * 
     * @param nums Array of integers
     * @return Array where each element is product of all other elements
     * @complexity Time: O(n), Space: O(1) excluding output array
     * @difficulty Medium
     * @see https://leetcode.com/problems/product-of-array-except-self/
     */
    static std::vector<int> productExceptSelf(std::vector<int>& nums);

    /**
     * @brief Find all unique triplets that sum to zero
     * 
     * Finds all unique triplets in the array which gives the sum of zero.
     * The solution set must not contain duplicate triplets.
     * 
     * @param nums Array of integers
     * @return Vector of vectors containing unique triplets [a, b, c] where a + b + c = 0
     * @complexity Time: O(n²), Space: O(1) excluding output
     * @difficulty Medium
     * @see https://leetcode.com/problems/3sum/
     */
    static std::vector<std::vector<int>> threeSum(std::vector<int>& nums);

    /**
     * @brief Container with most water
     * 
     * Finds two lines that together with the x-axis forms a container, such
     * that the container contains the most water. Returns the maximum area.
     * 
     * @param height Array where height[i] is the height of the i-th line
     * @return Maximum area of water that can be contained
     * @complexity Time: O(n), Space: O(1)
     * @difficulty Medium
     * @see https://leetcode.com/problems/container-with-most-water/
     */
    static int maxArea(std::vector<int>& height);
};

