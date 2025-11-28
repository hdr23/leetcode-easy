#include <gtest/gtest.h>
#include "StringProblems.h"

// 1. Reverse String
TEST(StringTests, ReverseString) {
    std::vector<char> s = {'h', 'e', 'l', 'l', 'o'};
    std::vector<char> expected = {'o', 'l', 'l', 'e', 'h'};
    StringProblems::reverseString(s);
    EXPECT_EQ(s, expected);
    
    std::vector<char> s2 = {'H', 'a', 'n', 'n', 'a', 'h'};
    std::vector<char> expected2 = {'h', 'a', 'n', 'n', 'a', 'H'};
    StringProblems::reverseString(s2);
    EXPECT_EQ(s2, expected2);
}

// 2. Reverse Integer
TEST(StringTests, ReverseInteger) {
    EXPECT_EQ(StringProblems::reverse(123), 321);
    EXPECT_EQ(StringProblems::reverse(-123), -321);
    EXPECT_EQ(StringProblems::reverse(120), 21);
    EXPECT_EQ(StringProblems::reverse(0), 0);
    // Test overflow cases
    EXPECT_EQ(StringProblems::reverse(2147483647), 0); // INT_MAX
    EXPECT_EQ(StringProblems::reverse(-2147483648), 0); // INT_MIN
}

// 3. First Unique Character
TEST(StringTests, FirstUniqChar) {
    EXPECT_EQ(StringProblems::firstUniqChar("leetcode"), 0);
    EXPECT_EQ(StringProblems::firstUniqChar("loveleetcode"), 2);
    EXPECT_EQ(StringProblems::firstUniqChar("aabb"), -1);
    EXPECT_EQ(StringProblems::firstUniqChar("a"), 0);
}

// 4. Valid Anagram
TEST(StringTests, IsAnagram) {
    EXPECT_TRUE(StringProblems::isAnagram("anagram", "nagaram"));
    EXPECT_FALSE(StringProblems::isAnagram("rat", "car"));
    EXPECT_TRUE(StringProblems::isAnagram("", ""));
    EXPECT_FALSE(StringProblems::isAnagram("a", "ab"));
}

// 5. Valid Palindrome
TEST(StringTests, IsPalindrome) {
    EXPECT_TRUE(StringProblems::isPalindrome("A man a plan a canal Panama"));
    EXPECT_FALSE(StringProblems::isPalindrome("race a car"));
    EXPECT_TRUE(StringProblems::isPalindrome(" "));
    EXPECT_TRUE(StringProblems::isPalindrome(""));
    EXPECT_TRUE(StringProblems::isPalindrome("a"));
    EXPECT_TRUE(StringProblems::isPalindrome("Madam"));
}

// 6. String to Integer (atoi)
TEST(StringTests, MyAtoi) {
    EXPECT_EQ(StringProblems::myAtoi("42"), 42);
    EXPECT_EQ(StringProblems::myAtoi("   -42"), -42);
    EXPECT_EQ(StringProblems::myAtoi("4193 with words"), 4193);
    EXPECT_EQ(StringProblems::myAtoi("words and 987"), 0);
    EXPECT_EQ(StringProblems::myAtoi("-91283472332"), -2147483648); // INT_MIN
    EXPECT_EQ(StringProblems::myAtoi("91283472332"), 2147483647); // INT_MAX
    EXPECT_EQ(StringProblems::myAtoi("   +42"), 42);
    EXPECT_EQ(StringProblems::myAtoi(""), 0);
    EXPECT_EQ(StringProblems::myAtoi("   "), 0);
}

// 7. Implement strStr
TEST(StringTests, StrStr) {
    EXPECT_EQ(StringProblems::strStr("sadbutsad", "sad"), 0);
    EXPECT_EQ(StringProblems::strStr("leetcode", "leeto"), -1);
    EXPECT_EQ(StringProblems::strStr("hello", "ll"), 2);
    EXPECT_EQ(StringProblems::strStr("", ""), 0);
    EXPECT_EQ(StringProblems::strStr("a", "a"), 0);
    EXPECT_EQ(StringProblems::strStr("mississippi", "issip"), 4);
}

// 8. Longest Common Prefix
TEST(StringTests, LongestCommonPrefix) {
    std::vector<std::string> strs1 = {"flower", "flow", "flight"};
    EXPECT_EQ(StringProblems::longestCommonPrefix(strs1), "fl");
    
    std::vector<std::string> strs2 = {"dog", "racecar", "car"};
    EXPECT_EQ(StringProblems::longestCommonPrefix(strs2), "");
    
    std::vector<std::string> strs3 = {"ab", "a"};
    EXPECT_EQ(StringProblems::longestCommonPrefix(strs3), "a");
    
    std::vector<std::string> strs4 = {"", "b"};
    EXPECT_EQ(StringProblems::longestCommonPrefix(strs4), "");
    
    std::vector<std::string> strs5 = {};
    EXPECT_EQ(StringProblems::longestCommonPrefix(strs5), "");
    
    std::vector<std::string> strs6 = {"a"};
    EXPECT_EQ(StringProblems::longestCommonPrefix(strs6), "a");
}

// 9. Longest Substring Without Repeating Characters
TEST(StringTests, LengthOfLongestSubstring) {
    EXPECT_EQ(StringProblems::lengthOfLongestSubstring("abcabcbb"), 3); // "abc"
    EXPECT_EQ(StringProblems::lengthOfLongestSubstring("bbbbb"), 1); // "b"
    EXPECT_EQ(StringProblems::lengthOfLongestSubstring("pwwkew"), 3); // "wke"
    EXPECT_EQ(StringProblems::lengthOfLongestSubstring(""), 0);
    EXPECT_EQ(StringProblems::lengthOfLongestSubstring(" "), 1);
    EXPECT_EQ(StringProblems::lengthOfLongestSubstring("dvdf"), 3); // "vdf"
}

// 10. Group Anagrams
TEST(StringTests, GroupAnagrams) {
    std::vector<std::string> strs1 = {"eat", "tea", "tan", "ate", "nat", "bat"};
    std::vector<std::vector<std::string>> result1 = StringProblems::groupAnagrams(strs1);
    EXPECT_EQ(result1.size(), 3); // Should have 3 groups
    
    std::vector<std::string> strs2 = {""};
    std::vector<std::vector<std::string>> result2 = StringProblems::groupAnagrams(strs2);
    EXPECT_EQ(result2.size(), 1);
    EXPECT_EQ(result2[0].size(), 1);
    
    std::vector<std::string> strs3 = {"a"};
    std::vector<std::vector<std::string>> result3 = StringProblems::groupAnagrams(strs3);
    EXPECT_EQ(result3.size(), 1);
    EXPECT_EQ(result3[0].size(), 1);
}

// 11. Longest Palindromic Substring
TEST(StringTests, LongestPalindrome) {
    std::string result1 = StringProblems::longestPalindrome("babad");
    EXPECT_TRUE(result1 == "bab" || result1 == "aba");
    
    EXPECT_EQ(StringProblems::longestPalindrome("cbbd"), "bb");
    EXPECT_EQ(StringProblems::longestPalindrome("a"), "a");
    EXPECT_EQ(StringProblems::longestPalindrome("ac"), "a");
    EXPECT_EQ(StringProblems::longestPalindrome("racecar"), "racecar");
    EXPECT_EQ(StringProblems::longestPalindrome(""), "");
}

