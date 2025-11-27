#include "Arrays.h"
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

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
int Arrays::removeDuplicates(std::vector<int>& nums) {
    if (nums.empty()) return 0;
    int k = 1;
    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] != nums[i - 1]) {
            nums[k] = nums[i];
            k++;
        }
    }
    return k;
}

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
int Arrays::maxProfit(std::vector<int>& prices) {
    int profit = 0;
    for (size_t i = 1; i < prices.size(); ++i) {
        if (prices[i] > prices[i - 1]) {
            profit += (prices[i] - prices[i - 1]);
        }
    }
    return profit;
}

/**
 * @brief Rotate array to the right by k steps
 * 
 * Rotates the array to the right by k steps in-place using the reverse algorithm.
 * 
 * @param nums Array to rotate (modified in-place)
 * @param k Number of steps to rotate right
 * @complexity Time: O(n), Space: O(1)
 */
void Arrays::rotate(std::vector<int>& nums, int k) {
    int n = nums.size();
    k %= n;
    std::reverse(nums.begin(), nums.end());
    std::reverse(nums.begin(), nums.begin() + k);
    std::reverse(nums.begin() + k, nums.end());
}

/**
 * @brief Check if array contains any duplicate elements
 * 
 * Determines if any value appears at least twice in the array.
 * 
 * @param nums Array of integers to check
 * @return true if duplicates exist, false otherwise
 * @complexity Time: O(n), Space: O(n)
 */
bool Arrays::containsDuplicate(std::vector<int>& nums) {
    std::unordered_set<int> seen;
    for (int num : nums) {
        if (seen.count(num)) return true;
        seen.insert(num);
    }
    return false;
}

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
int Arrays::singleNumber(std::vector<int>& nums) {
    int result = 0;
    for (int num : nums) {
        result ^= num;
    }
    return result;
}

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
std::vector<int> Arrays::intersect(std::vector<int>& nums1, std::vector<int>& nums2) {
    std::unordered_map<int, int> counts;
    for (int num : nums1) counts[num]++;
    
    std::vector<int> result;
    for (int num : nums2) {
        if (counts[num] > 0) {
            result.push_back(num);
            counts[num]--;
        }
    }
    return result;
}

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
std::vector<int> Arrays::plusOne(std::vector<int>& digits) {
    for (int i = digits.size() - 1; i >= 0; --i) {
        if (digits[i] < 9) {
            digits[i]++;
            return digits;
        }
        digits[i] = 0;
    }
    // If we are here, it means we had 999... -> 1000...
    digits.insert(digits.begin(), 1);
    return digits;
}

/**
 * @brief Move all zeros to the end while maintaining relative order
 * 
 * Moves all 0's to the end of the array while maintaining the relative order
 * of the non-zero elements. Performed in-place.
 * 
 * @param nums Array to modify (modified in-place)
 * @complexity Time: O(n), Space: O(1)
 */
void Arrays::moveZeroes(std::vector<int>& nums) {
    int insertPos = 0;
    for (int num : nums) {
        if (num != 0) {
            nums[insertPos++] = num;
        }
    }
    while (insertPos < nums.size()) {
        nums[insertPos++] = 0;
    }
}

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
std::vector<int> Arrays::twoSum(std::vector<int>& nums, int target) {
    std::unordered_map<int, int> lookup;
    for (int i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i];
        if (lookup.count(complement)) {
            return {lookup[complement], i};
        }
        lookup[nums[i]] = i;
    }
    return {};
}

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
bool Arrays::isValidSudoku(std::vector<std::vector<char>>& board) {
    bool rows[9][9] = {false};
    bool cols[9][9] = {false};
    bool boxes[9][9] = {false};
    
    for (int r = 0; r < 9; ++r) {
        for (int c = 0; c < 9; ++c) {
            if (board[r][c] == '.') continue;
            
            int num = board[r][c] - '1'; // 0-8 index
            int boxIndex = (r / 3) * 3 + (c / 3);
            
            if (rows[r][num] || cols[c][num] || boxes[boxIndex][num]) {
                return false;
            }
            
            rows[r][num] = true;
            cols[c][num] = true;
            boxes[boxIndex][num] = true;
        }
    }
    return true;
}

/**
 * @brief Rotate a 2D matrix 90 degrees clockwise
 * 
 * Rotates an n x n 2D matrix by 90 degrees clockwise in-place.
 * Uses transpose and reverse operations.
 * 
 * @param matrix n x n matrix to rotate (modified in-place)
 * @complexity Time: O(n²), Space: O(1)
 */
void Arrays::rotateImage(std::vector<std::vector<int>>& matrix) {
    int n = matrix.size();
    // Transpose
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            std::swap(matrix[i][j], matrix[j][i]);
        }
    }
    // Reverse each row
    for (int i = 0; i < n; ++i) {
        std::reverse(matrix[i].begin(), matrix[i].end());
    }
}