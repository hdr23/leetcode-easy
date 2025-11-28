#include "OtherProblems.h"
#include <stack>
#include <algorithm>

int OtherProblems::hammingWeight(uint32_t n) {
    int count = 0;
    while (n != 0) {
        count += n & 1;  // Check if the least significant bit is 1
        n >>= 1;         // Right shift by 1
    }
    return count;
}

uint32_t OtherProblems::reverseBits(uint32_t n) {
    uint32_t result = 0;
    for (int i = 0; i < 32; i++) {
        result <<= 1;           // Shift result left to make room for next bit
        result |= (n & 1);      // Add the least significant bit of n
        n >>= 1;                // Shift n right to process next bit
    }
    return result;
}

int OtherProblems::missingNumber(std::vector<int>& nums) {
    int n = nums.size();
    int expectedSum = n * (n + 1) / 2;  // Sum of 0 to n
    int actualSum = 0;
    
    for (int num : nums) {
        actualSum += num;
    }
    
    return expectedSum - actualSum;
}

bool OtherProblems::isValid(std::string s) {
    std::stack<char> st;
    
    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        } else {
            if (st.empty()) {
                return false;  // No matching opening bracket
            }
            
            char top = st.top();
            st.pop();
            
            // Check if the closing bracket matches the opening bracket
            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')) {
                return false;
            }
        }
    }
    
    return st.empty();  // Stack should be empty if all brackets are matched
}

int OtherProblems::climbStairs(int n) {
    if (n <= 2) {
        return n;
    }
    
    // Fibonacci-like sequence: ways(n) = ways(n-1) + ways(n-2)
    int prev2 = 1;  // ways to reach step 1
    int prev1 = 2;  // ways to reach step 2
    
    for (int i = 3; i <= n; i++) {
        int current = prev1 + prev2;
        prev2 = prev1;
        prev1 = current;
    }
    
    return prev1;
}

