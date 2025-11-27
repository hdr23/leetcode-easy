#include <strings.h>
#include <gtest/gtest.h>
#include "ArrayProblems.h"

// 1. Remove Duplicates
TEST(ArrayTests, RemoveDuplicates) {
    std::vector<int> nums = {1, 1, 2};
    int k = ArrayProblems::removeDuplicates(nums);
    EXPECT_EQ(k, 2);
    EXPECT_EQ(nums[0], 1);
    EXPECT_EQ(nums[1], 2);
}

// 2. Best Time to Buy and Sell Stock II
TEST(ArrayTests, MaxProfitII) {
    std::vector<int> prices = {7, 1, 5, 3, 6, 4};
    // Buy at 1, sell at 5 (profit 4). Buy at 3, sell at 6 (profit 3). Total 7.
    EXPECT_EQ(ArrayProblems::maxProfit(prices), 7);
    
    std::vector<int> prices2 = {1, 2, 3, 4, 5};
    EXPECT_EQ(ArrayProblems::maxProfit(prices2), 4);
}

// 3. Rotate Array
TEST(ArrayTests, RotateArray) {
    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    std::vector<int> expected = {5, 6, 7, 1, 2, 3, 4};
    ArrayProblems::rotate(nums, 3);
    EXPECT_EQ(nums, expected);
}

// 4. Contains Duplicate
TEST(ArrayTests, ContainsDuplicate) {
    std::vector<int> nums1 = {1, 2, 3, 1};
    EXPECT_TRUE(ArrayProblems::containsDuplicate(nums1));
    
    std::vector<int> nums2 = {1, 2, 3, 4};
    EXPECT_FALSE(ArrayProblems::containsDuplicate(nums2));
}

// 5. Single Number
TEST(ArrayTests, SingleNumber) {
    std::vector<int> nums = {4, 1, 2, 1, 2};
    EXPECT_EQ(ArrayProblems::singleNumber(nums), 4);
}

// 6. Intersection of Two Arrays II
TEST(ArrayTests, Intersect) {
    std::vector<int> nums1 = {1, 2, 2, 1};
    std::vector<int> nums2 = {2, 2};
    std::vector<int> res = ArrayProblems::intersect(nums1, nums2);
    EXPECT_EQ(res.size(), 2);
    EXPECT_EQ(res[0], 2); 
    EXPECT_EQ(res[1], 2);
}

// 7. Plus One
TEST(ArrayTests, PlusOne) {
    std::vector<int> digits = {1, 2, 3};
    std::vector<int> expected = {1, 2, 4};
    EXPECT_EQ(ArrayProblems::plusOne(digits), expected);
    
    std::vector<int> nine = {9};
    std::vector<int> expectedNine = {1, 0};
    EXPECT_EQ(ArrayProblems::plusOne(nine), expectedNine);
}

// 8. Move Zeroes
TEST(ArrayTests, MoveZeroes) {
    std::vector<int> nums = {0, 1, 0, 3, 12};
    std::vector<int> expected = {1, 3, 12, 0, 0};
    ArrayProblems::moveZeroes(nums);
    EXPECT_EQ(nums, expected);
}

// 9. Two Sum
TEST(ArrayTests, TwoSum) {
    std::vector<int> nums = {2, 7, 11, 15};
    std::vector<int> expected = {0, 1};
    EXPECT_EQ(ArrayProblems::twoSum(nums, 9), expected);
}

// 10. Valid Sudoku
TEST(ArrayTests, ValidSudoku) {
    std::vector<std::vector<char>> board(9, std::vector<char>(9, '.'));
    // Fill first row with valid numbers
    board[0] = {'5','3','.','.','7','.','.','.','.'};
    board[1] = {'6','.','.','1','9','5','.','.','.'};
    board[2] = {'.','9','8','.','.','.','.','6','.'};
    // ... Assume rest are dots for brevity, sufficient for simple test
    EXPECT_TRUE(ArrayProblems::isValidSudoku(board));
    
    // Add a conflict
    board[0][0] = '5';
    board[0][1] = '5'; // Duplicate in row
    EXPECT_FALSE(ArrayProblems::isValidSudoku(board));
}

// 11. Rotate Image
TEST(ArrayTests, RotateImage) {
    std::vector<std::vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    std::vector<std::vector<int>> expected = {
        {7, 4, 1},
        {8, 5, 2},
        {9, 6, 3}
    };
    ArrayProblems::rotateImage(matrix);
    EXPECT_EQ(matrix, expected);
}