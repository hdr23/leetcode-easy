#include <gtest/gtest.h>
#include "LinkedListProblems.h"
#include <vector>

// Helper function to create a linked list from a vector
ListNode* createList(const std::vector<int>& values) {
    if (values.empty()) {
        return nullptr;
    }
    
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    
    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    
    return head;
}

// Helper function to convert a linked list to a vector
std::vector<int> listToVector(ListNode* head) {
    std::vector<int> result;
    ListNode* current = head;
    
    while (current != nullptr) {
        result.push_back(current->val);
        current = current->next;
    }
    
    return result;
}

// Helper function to delete a linked list
void deleteList(ListNode* head) {
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

// Helper function to get the nth node (0-indexed)
ListNode* getNode(ListNode* head, int index) {
    ListNode* current = head;
    for (int i = 0; i < index && current != nullptr; ++i) {
        current = current->next;
    }
    return current;
}

// 1. Delete Node in a Linked List
TEST(LinkedListTests, DeleteNode) {
    // Test case: [4,5,1,9], delete node 5
    ListNode* head = createList({4, 5, 1, 9});
    ListNode* nodeToDelete = getNode(head, 1); // node with value 5
    LinkedListProblems::deleteNode(nodeToDelete);
    
    std::vector<int> expected = {4, 1, 9};
    std::vector<int> result = listToVector(head);
    EXPECT_EQ(result, expected);
    
    deleteList(head);
    
    // Test case: [1,2,3,4], delete node 3
    head = createList({1, 2, 3, 4});
    nodeToDelete = getNode(head, 2); // node with value 3
    LinkedListProblems::deleteNode(nodeToDelete);
    
    expected = {1, 2, 4};
    result = listToVector(head);
    EXPECT_EQ(result, expected);
    
    deleteList(head);
}

// 2. Remove Nth Node From End of List
TEST(LinkedListTests, RemoveNthFromEnd) {
    // Test case: [1,2,3,4,5], n=2 -> [1,2,3,5]
    ListNode* head = createList({1, 2, 3, 4, 5});
    head = LinkedListProblems::removeNthFromEnd(head, 2);
    
    std::vector<int> expected = {1, 2, 3, 5};
    std::vector<int> result = listToVector(head);
    EXPECT_EQ(result, expected);
    
    deleteList(head);
    
    // Test case: [1], n=1 -> []
    head = createList({1});
    head = LinkedListProblems::removeNthFromEnd(head, 1);
    
    expected = {};
    result = listToVector(head);
    EXPECT_EQ(result, expected);
    
    deleteList(head);
    
    // Test case: [1,2], n=2 -> [2]
    head = createList({1, 2});
    head = LinkedListProblems::removeNthFromEnd(head, 2);
    
    expected = {2};
    result = listToVector(head);
    EXPECT_EQ(result, expected);
    
    deleteList(head);
}

// 3. Reverse Linked List
TEST(LinkedListTests, ReverseList) {
    // Test case: [1,2,3,4,5] -> [5,4,3,2,1]
    ListNode* head = createList({1, 2, 3, 4, 5});
    head = LinkedListProblems::reverseList(head);
    
    std::vector<int> expected = {5, 4, 3, 2, 1};
    std::vector<int> result = listToVector(head);
    EXPECT_EQ(result, expected);
    
    deleteList(head);
    
    // Test case: [1,2] -> [2,1]
    head = createList({1, 2});
    head = LinkedListProblems::reverseList(head);
    
    expected = {2, 1};
    result = listToVector(head);
    EXPECT_EQ(result, expected);
    
    deleteList(head);
    
    // Test case: [] -> []
    head = nullptr;
    head = LinkedListProblems::reverseList(head);
    EXPECT_EQ(head, nullptr);
    
    // Test case: [1] -> [1]
    head = createList({1});
    head = LinkedListProblems::reverseList(head);
    
    expected = {1};
    result = listToVector(head);
    EXPECT_EQ(result, expected);
    
    deleteList(head);
}

// 4. Merge Two Sorted Lists
TEST(LinkedListTests, MergeTwoLists) {
    // Test case: [1,2,4] and [1,3,4] -> [1,1,2,3,4,4]
    ListNode* list1 = createList({1, 2, 4});
    ListNode* list2 = createList({1, 3, 4});
    ListNode* merged = LinkedListProblems::mergeTwoLists(list1, list2);
    
    std::vector<int> expected = {1, 1, 2, 3, 4, 4};
    std::vector<int> result = listToVector(merged);
    EXPECT_EQ(result, expected);
    
    deleteList(merged);
    
    // Test case: [] and [] -> []
    list1 = nullptr;
    list2 = nullptr;
    merged = LinkedListProblems::mergeTwoLists(list1, list2);
    EXPECT_EQ(merged, nullptr);
    
    // Test case: [] and [0] -> [0]
    list1 = nullptr;
    list2 = createList({0});
    merged = LinkedListProblems::mergeTwoLists(list1, list2);
    
    expected = {0};
    result = listToVector(merged);
    EXPECT_EQ(result, expected);
    
    deleteList(merged);
    
    // Test case: [1,2,3] and [4,5,6] -> [1,2,3,4,5,6]
    list1 = createList({1, 2, 3});
    list2 = createList({4, 5, 6});
    merged = LinkedListProblems::mergeTwoLists(list1, list2);
    
    expected = {1, 2, 3, 4, 5, 6};
    result = listToVector(merged);
    EXPECT_EQ(result, expected);
    
    deleteList(merged);
}

// 5. Palindrome Linked List
TEST(LinkedListTests, IsPalindrome) {
    // Test case: [1,2,2,1] -> true
    ListNode* head = createList({1, 2, 2, 1});
    EXPECT_TRUE(LinkedListProblems::isPalindrome(head));
    deleteList(head);
    
    // Test case: [1,2] -> false
    head = createList({1, 2});
    EXPECT_FALSE(LinkedListProblems::isPalindrome(head));
    deleteList(head);
    
    // Test case: [1] -> true
    head = createList({1});
    EXPECT_TRUE(LinkedListProblems::isPalindrome(head));
    deleteList(head);
    
    // Test case: [] -> true
    head = nullptr;
    EXPECT_TRUE(LinkedListProblems::isPalindrome(head));
    
    // Test case: [1,2,3,2,1] -> true
    head = createList({1, 2, 3, 2, 1});
    EXPECT_TRUE(LinkedListProblems::isPalindrome(head));
    deleteList(head);
    
    // Test case: [1,2,3,4] -> false
    head = createList({1, 2, 3, 4});
    EXPECT_FALSE(LinkedListProblems::isPalindrome(head));
    deleteList(head);
}

// 6. Linked List Cycle
TEST(LinkedListTests, HasCycle) {
    // Test case: [3,2,0,-4] with cycle at position 1
    ListNode* head = new ListNode(3);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(0);
    ListNode* node4 = new ListNode(-4);
    
    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node2; // Create cycle
    
    EXPECT_TRUE(LinkedListProblems::hasCycle(head));
    
    // Break the cycle to avoid issues with delete
    node4->next = nullptr;
    deleteList(head);
    
    // Test case: [1,2] with cycle at position 0
    head = new ListNode(1);
    node2 = new ListNode(2);
    head->next = node2;
    node2->next = head; // Create cycle
    
    EXPECT_TRUE(LinkedListProblems::hasCycle(head));
    
    // Break the cycle
    node2->next = nullptr;
    deleteList(head);
    
    // Test case: [1] with no cycle
    head = createList({1});
    EXPECT_FALSE(LinkedListProblems::hasCycle(head));
    deleteList(head);
    
    // Test case: [] with no cycle
    head = nullptr;
    EXPECT_FALSE(LinkedListProblems::hasCycle(head));
    
    // Test case: [1,2,3,4] with no cycle
    head = createList({1, 2, 3, 4});
    EXPECT_FALSE(LinkedListProblems::hasCycle(head));
    deleteList(head);
}

