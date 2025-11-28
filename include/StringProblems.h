#pragma once
#include <vector>
#include <string>

class StringProblems {
public:
    /**
     * @brief Reverse a string in-place
     * 
     * Reverses a string represented as an array of characters in-place.
     * 
     * @param s String represented as vector of characters (modified in-place)
     * @complexity Time: O(n), Space: O(1)
     * @difficulty Easy
     * @see https://leetcode.com/problems/reverse-string/
     */
    static void reverseString(std::vector<char>& s);

    /**
     * @brief Reverse digits of an integer
     * 
     * Reverses the digits of a signed 32-bit integer. If reversing causes
     * overflow, returns 0.
     * 
     * @param x Integer to reverse
     * @return Reversed integer, or 0 if overflow occurs
     * @complexity Time: O(log(x)), Space: O(1)
     * @difficulty Medium
     * @see https://leetcode.com/problems/reverse-integer/
     */
    static int reverse(int x);

    /**
     * @brief Find first unique character in a string
     * 
     * Finds the index of the first non-repeating character in the string.
     * Returns -1 if no such character exists.
     * 
     * @param s Input string
     * @return Index of first unique character, or -1 if none exists
     * @complexity Time: O(n), Space: O(1) - fixed size alphabet array
     * @difficulty Easy
     * @see https://leetcode.com/problems/first-unique-character-in-a-string/
     */
    static int firstUniqChar(std::string s);

    /**
     * @brief Check if two strings are anagrams
     * 
     * Determines if string t is an anagram of string s. An anagram is
     * a word formed by rearranging the letters of another word.
     * 
     * @param s First string
     * @param t Second string
     * @return true if t is an anagram of s, false otherwise
     * @complexity Time: O(n + m), Space: O(1) - fixed size alphabet array
     * @difficulty Easy
     * @see https://leetcode.com/problems/valid-anagram/
     */
    static bool isAnagram(std::string s, std::string t);

    /**
     * @brief Check if string is a valid palindrome
     * 
     * Determines if a string is a palindrome, considering only alphanumeric
     * characters and ignoring cases.
     * 
     * @param s Input string
     * @return true if string is a palindrome, false otherwise
     * @complexity Time: O(n), Space: O(1)
     * @difficulty Easy
     * @see https://leetcode.com/problems/valid-palindrome/
     */
    static bool isPalindrome(std::string s);

    /**
     * @brief Convert string to integer (atoi)
     * 
     * Implements the myAtoi function which converts a string to a 32-bit
     * signed integer. Handles leading whitespace, optional sign, and overflow.
     * 
     * @param s Input string to convert
     * @return Converted integer, clamped to 32-bit signed integer range
     * @complexity Time: O(n), Space: O(1)
     * @difficulty Medium
     * @see https://leetcode.com/problems/string-to-integer-atoi/
     */
    static int myAtoi(std::string s);

    /**
     * @brief Find first occurrence of substring (strStr)
     * 
     * Returns the index of the first occurrence of needle in haystack,
     * or -1 if needle is not part of haystack.
     * 
     * @param haystack String to search in
     * @param needle Substring to find
     * @return Index of first occurrence, or -1 if not found
     * @complexity Time: O(n * m) where n=haystack.length(), m=needle.length(), Space: O(1)
     * @difficulty Easy
     * @see https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/
     */
    static int strStr(std::string haystack, std::string needle);

    /**
     * @brief Find longest common prefix among strings
     * 
     * Finds the longest common prefix string amongst an array of strings.
     * If there is no common prefix, returns an empty string.
     * 
     * @param strs Vector of strings
     * @return Longest common prefix string
     * @complexity Time: O(S) where S is sum of all characters, Space: O(1)
     * @difficulty Easy
     * @see https://leetcode.com/problems/longest-common-prefix/
     */
    static std::string longestCommonPrefix(std::vector<std::string>& strs);

    /**
     * @brief Find length of longest substring without repeating characters
     * 
     * Finds the length of the longest substring without repeating characters.
     * Uses sliding window technique.
     * 
     * @param s Input string
     * @return Length of longest substring without repeating characters
     * @complexity Time: O(n), Space: O(min(n, m)) where m is charset size
     * @difficulty Medium
     * @see https://leetcode.com/problems/longest-substring-without-repeating-characters/
     */
    static int lengthOfLongestSubstring(std::string s);

    /**
     * @brief Group anagrams together
     * 
     * Groups strings that are anagrams of each other together.
     * Returns a vector of groups, where each group contains anagrams.
     * 
     * @param strs Vector of strings to group
     * @return Vector of groups, where each group is a vector of anagram strings
     * @complexity Time: O(n * k * log(k)) where n is number of strings, k is average length
     * @difficulty Medium
     * @see https://leetcode.com/problems/group-anagrams/
     */
    static std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs);

    /**
     * @brief Find longest palindromic substring
     * 
     * Finds the longest palindromic substring in a given string.
     * Uses expand around centers approach.
     * 
     * @param s Input string
     * @return Longest palindromic substring
     * @complexity Time: O(n²), Space: O(1)
     * @difficulty Medium
     * @see https://leetcode.com/problems/longest-palindromic-substring/
     */
    static std::string longestPalindrome(std::string s);
};


