#include "ArrayProblems.h"
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

int ArrayProblems::removeDuplicates(std::vector<int>& nums) {
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

int ArrayProblems::maxProfit(std::vector<int>& prices) {
    int profit = 0;
    for (size_t i = 1; i < prices.size(); ++i) {
        if (prices[i] > prices[i - 1]) {
            profit += (prices[i] - prices[i - 1]);
        }
    }
    return profit;
}

void ArrayProblems::rotate(std::vector<int>& nums, int k) {
    int n = nums.size();
    k %= n;
    std::reverse(nums.begin(), nums.end());
    std::reverse(nums.begin(), nums.begin() + k);
    std::reverse(nums.begin() + k, nums.end());
}

bool ArrayProblems::containsDuplicate(std::vector<int>& nums) {
    std::unordered_set<int> seen;
    for (int num : nums) {
        if (seen.count(num)) return true;
        seen.insert(num);
    }
    return false;
}

int ArrayProblems::singleNumber(std::vector<int>& nums) {
    int result = 0;
    for (int num : nums) {
        result ^= num;
    }
    return result;
}

std::vector<int> ArrayProblems::intersect(std::vector<int>& nums1, std::vector<int>& nums2) {
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

std::vector<int> ArrayProblems::plusOne(std::vector<int>& digits) {
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

void ArrayProblems::moveZeroes(std::vector<int>& nums) {
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

std::vector<int> ArrayProblems::twoSum(std::vector<int>& nums, int target) {
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

bool ArrayProblems::isValidSudoku(std::vector<std::vector<char>>& board) {
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

void ArrayProblems::rotateImage(std::vector<std::vector<int>>& matrix) {
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

int ArrayProblems::maxSubArray(std::vector<int>& nums) {
    int maxSum = nums[0];
    int currentSum = nums[0];
    
    for (size_t i = 1; i < nums.size(); ++i) {
        // Either extend the previous subarray or start a new one
        currentSum = std::max(nums[i], currentSum + nums[i]);
        maxSum = std::max(maxSum, currentSum);
    }
    
    return maxSum;
}

std::vector<int> ArrayProblems::productExceptSelf(std::vector<int>& nums) {
    int n = nums.size();
    std::vector<int> result(n, 1);
    
    // First pass: calculate left products
    for (int i = 1; i < n; ++i) {
        result[i] = result[i - 1] * nums[i - 1];
    }
    
    // Second pass: multiply by right products
    int rightProduct = 1;
    for (int i = n - 1; i >= 0; --i) {
        result[i] *= rightProduct;
        rightProduct *= nums[i];
    }
    
    return result;
}

std::vector<std::vector<int>> ArrayProblems::threeSum(std::vector<int>& nums) {
    std::vector<std::vector<int>> result;
    int n = nums.size();
    
    if (n < 3) {
        return result;
    }
    
    // Sort the array
    std::sort(nums.begin(), nums.end());
    
    for (int i = 0; i < n - 2; ++i) {
        // Skip duplicates for the first number
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }
        
        int left = i + 1;
        int right = n - 1;
        
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            
            if (sum == 0) {
                result.push_back({nums[i], nums[left], nums[right]});
                
                // Skip duplicates for the second number
                while (left < right && nums[left] == nums[left + 1]) {
                    left++;
                }
                // Skip duplicates for the third number
                while (left < right && nums[right] == nums[right - 1]) {
                    right--;
                }
                
                left++;
                right--;
            } else if (sum < 0) {
                left++;
            } else {
                right--;
            }
        }
    }
    
    return result;
}

int ArrayProblems::maxArea(std::vector<int>& height) {
    int maxArea = 0;
    int left = 0;
    int right = height.size() - 1;
    
    while (left < right) {
        int width = right - left;
        int currentArea = std::min(height[left], height[right]) * width;
        maxArea = std::max(maxArea, currentArea);
        
        // Move the pointer with smaller height
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }
    
    return maxArea;
}

