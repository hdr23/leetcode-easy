#pragma once
#include "SharedStructs.h"

class LinkedListProblems {
public:
    /**
     * @brief Delete a node in a linked list (except the tail)
     * 
     * Deletes a node in a singly-linked list, given only access to that node.
     * The node is guaranteed not to be the tail of the list.
     * 
     * @param node The node to delete (modified in-place)
     * @complexity Time: O(1), Space: O(1)
     */
    static void deleteNode(ListNode* node);

    /**
     * @brief Remove the nth node from the end of the list
     * 
     * Removes the nth node from the end of the list and returns the head.
     * 
     * @param head Head of the linked list
     * @param n Position from the end (1-indexed)
     * @return Head of the modified list
     * @complexity Time: O(L) where L is the length of the list, Space: O(1)
     */
    static ListNode* removeNthFromEnd(ListNode* head, int n);

    /**
     * @brief Reverse a linked list
     * 
     * Reverses a singly linked list and returns the new head.
     * 
     * @param head Head of the linked list
     * @return Head of the reversed list
     * @complexity Time: O(n), Space: O(1)
     */
    static ListNode* reverseList(ListNode* head);

    /**
     * @brief Merge two sorted linked lists
     * 
     * Merges two sorted linked lists and returns it as a new sorted list.
     * The new list should be made by splicing together the nodes of the first two lists.
     * 
     * @param list1 Head of the first sorted list
     * @param list2 Head of the second sorted list
     * @return Head of the merged sorted list
     * @complexity Time: O(n + m), Space: O(1)
     */
    static ListNode* mergeTwoLists(ListNode* list1, ListNode* list2);

    /**
     * @brief Check if a linked list is a palindrome
     * 
     * Determines if a singly linked list is a palindrome.
     * 
     * @param head Head of the linked list
     * @return true if the list is a palindrome, false otherwise
     * @complexity Time: O(n), Space: O(1)
     */
    static bool isPalindrome(ListNode* head);

    /**
     * @brief Detect if a linked list has a cycle
     * 
     * Determines if a linked list has a cycle in it using Floyd's cycle detection algorithm.
     * 
     * @param head Head of the linked list
     * @return true if there is a cycle, false otherwise
     * @complexity Time: O(n), Space: O(1)
     */
    static bool hasCycle(ListNode* head);
};

