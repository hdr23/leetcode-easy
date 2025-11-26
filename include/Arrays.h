#pragma once
#include <vector>
#include <algorithm>

class Arrays {
public:
    // 1. Remove Duplicates from Sorted Array
    // Returns the number of unique elements
    static int removeDuplicates(std::vector<int>& nums);

    // 2. Best Time to Buy and Sell Stock II
    // Multiple transactions allowed to maximize profit
    static int maxProfit(std::vector<int>& prices);

    // 3. Rotate Array
    // Rotate array to the right by k steps
    static void rotate(std::vector<int>& nums, int k);

    // 4. Contains Duplicate
    // Returns true if any value appears at least twice
    static bool containsDuplicate(std::vector<int>& nums);

    // 5. Single Number
    // Find the one element that appears only once (others appear twice)
    static int singleNumber(std::vector<int>& nums);

    // 6. Intersection of Two Arrays II
    // Return intersection (respecting frequency)
    static std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2);

    // 7. Plus One
    // Increment the large integer represented by the array
    static std::vector<int> plusOne(std::vector<int>& digits);

    // 8. Move Zeroes
    // Move all 0's to the end while maintaining relative order
    static void moveZeroes(std::vector<int>& nums);

    // 9. Two Sum
    // Return indices of the two numbers that add up to target
    static std::vector<int> twoSum(std::vector<int>& nums, int target);

    // 10. Valid Sudoku
    // Determine if a 9x9 Sudoku board is valid (only filled cells need validation)
    static bool isValidSudoku(std::vector<std::vector<char>>& board);

    // 11. Rotate Image
    // Rotate the n x n 2D matrix by 90 degrees (clockwise)
    static void rotateImage(std::vector<std::vector<int>>& matrix);
};