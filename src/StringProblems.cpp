#include "StringProblems.h"
#include <algorithm>
#include <cctype>
#include <climits>
#include <unordered_map>

void StringProblems::reverseString(std::vector<char>& s) {
    int left = 0;
    int right = s.size() - 1;
    while (left < right) {
        std::swap(s[left], s[right]);
        left++;
        right--;
    }
}

int StringProblems::reverse(int x) {
    int reversed = 0;
    while (x != 0) {
        int digit = x % 10;
        x /= 10;
        
        // Check for overflow before multiplying
        if (reversed > INT_MAX / 10 || (reversed == INT_MAX / 10 && digit > 7)) {
            return 0;
        }
        if (reversed < INT_MIN / 10 || (reversed == INT_MIN / 10 && digit < -8)) {
            return 0;
        }
        
        reversed = reversed * 10 + digit;
    }
    return reversed;
}

int StringProblems::firstUniqChar(std::string s) {
    int count[26] = {0};
    
    // Count frequency of each character
    for (char c : s) {
        count[c - 'a']++;
    }
    
    // Find first character with count 1
    for (int i = 0; i < s.length(); ++i) {
        if (count[s[i] - 'a'] == 1) {
            return i;
        }
    }
    
    return -1;
}

bool StringProblems::isAnagram(std::string s, std::string t) {
    if (s.length() != t.length()) {
        return false;
    }
    
    int count[26] = {0};
    
    // Count characters in s
    for (char c : s) {
        count[c - 'a']++;
    }
    
    // Decrement count for characters in t
    for (char c : t) {
        count[c - 'a']--;
        if (count[c - 'a'] < 0) {
            return false;
        }
    }
    
    return true;
}

bool StringProblems::isPalindrome(std::string s) {
    int left = 0;
    int right = s.length() - 1;
    
    while (left < right) {
        // Skip non-alphanumeric characters from left
        while (left < right && !std::isalnum(s[left])) {
            left++;
        }
        // Skip non-alphanumeric characters from right
        while (left < right && !std::isalnum(s[right])) {
            right--;
        }
        
        // Compare characters (case-insensitive)
        if (std::tolower(s[left]) != std::tolower(s[right])) {
            return false;
        }
        
        left++;
        right--;
    }
    
    return true;
}

int StringProblems::myAtoi(std::string s) {
    int i = 0;
    int n = s.length();
    
    // Skip leading whitespace
    while (i < n && s[i] == ' ') {
        i++;
    }
    
    if (i >= n) {
        return 0;
    }
    
    // Determine sign
    int sign = 1;
    if (s[i] == '+' || s[i] == '-') {
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }
    
    // Convert digits
    int result = 0;
    while (i < n && std::isdigit(s[i])) {
        int digit = s[i] - '0';
        
        // Check for overflow before multiplying
        if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > 7)) {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }
        
        result = result * 10 + digit;
        i++;
    }
    
    return sign * result;
}

int StringProblems::strStr(std::string haystack, std::string needle) {
    if (needle.empty()) {
        return 0;
    }
    
    int haystackLen = haystack.length();
    int needleLen = needle.length();
    
    if (needleLen > haystackLen) {
        return -1;
    }
    
    for (int i = 0; i <= haystackLen - needleLen; ++i) {
        int j = 0;
        while (j < needleLen && haystack[i + j] == needle[j]) {
            j++;
        }
        if (j == needleLen) {
            return i;
        }
    }
    
    return -1;
}

std::string StringProblems::longestCommonPrefix(std::vector<std::string>& strs) {
    if (strs.empty()) {
        return "";
    }
    
    // Use first string as reference
    std::string prefix = strs[0];
    
    for (int i = 1; i < strs.size(); ++i) {
        // Compare current prefix with each string
        int j = 0;
        while (j < prefix.length() && j < strs[i].length() && prefix[j] == strs[i][j]) {
            j++;
        }
        prefix = prefix.substr(0, j);
        
        // Early exit if prefix becomes empty
        if (prefix.empty()) {
            return "";
        }
    }
    
    return prefix;
}

int StringProblems::lengthOfLongestSubstring(std::string s) {
    std::unordered_map<char, int> charIndex;
    int maxLength = 0;
    int start = 0;
    
    for (int end = 0; end < s.length(); ++end) {
        // If character is seen before and is within current window
        if (charIndex.count(s[end]) && charIndex[s[end]] >= start) {
            start = charIndex[s[end]] + 1;
        }
        
        charIndex[s[end]] = end;
        maxLength = std::max(maxLength, end - start + 1);
    }
    
    return maxLength;
}

std::vector<std::vector<std::string>> StringProblems::groupAnagrams(std::vector<std::string>& strs) {
    std::unordered_map<std::string, std::vector<std::string>> groups;
    
    for (const std::string& str : strs) {
        std::string key = str;
        std::sort(key.begin(), key.end());
        groups[key].push_back(str);
    }
    
    std::vector<std::vector<std::string>> result;
    for (auto& pair : groups) {
        result.push_back(pair.second);
    }
    
    return result;
}

namespace {
    // Helper function to expand around center for palindrome
    int expandAroundCenter(const std::string& s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1;
    }
}

std::string StringProblems::longestPalindrome(std::string s) {
    if (s.empty()) {
        return "";
    }
    
    int start = 0;
    int maxLength = 1;
    
    for (int i = 0; i < s.length(); ++i) {
        // Check for odd-length palindromes (center at i)
        int len1 = expandAroundCenter(s, i, i);
        // Check for even-length palindromes (center between i and i+1)
        int len2 = expandAroundCenter(s, i, i + 1);
        
        int len = std::max(len1, len2);
        
        if (len > maxLength) {
            maxLength = len;
            start = i - (len - 1) / 2;
        }
    }
    
    return s.substr(start, maxLength);
}


