#include "LinkedListProblems.h"

void LinkedListProblems::deleteNode(ListNode* node) {
    // Since we can't access the previous node, we copy the next node's value
    // and delete the next node instead
    if (node == nullptr || node->next == nullptr) {
        return; // Invalid input or tail node
    }
    
    ListNode* nextNode = node->next;
    node->val = nextNode->val;
    node->next = nextNode->next;
    delete nextNode;
}

ListNode* LinkedListProblems::removeNthFromEnd(ListNode* head, int n) {
    // Use two pointers: fast and slow
    // Move fast pointer n+1 steps ahead, then move both until fast reaches end
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    
    ListNode* fast = dummy;
    ListNode* slow = dummy;
    
    // Move fast pointer n+1 steps ahead
    for (int i = 0; i <= n; ++i) {
        fast = fast->next;
    }
    
    // Move both pointers until fast reaches the end
    while (fast != nullptr) {
        fast = fast->next;
        slow = slow->next;
    }
    
    // Now slow is pointing to the node before the one to delete
    ListNode* nodeToDelete = slow->next;
    slow->next = slow->next->next;
    delete nodeToDelete;
    
    ListNode* newHead = dummy->next;
    delete dummy;
    return newHead;
}

ListNode* LinkedListProblems::reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* current = head;
    
    while (current != nullptr) {
        ListNode* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    return prev;
}

ListNode* LinkedListProblems::mergeTwoLists(ListNode* list1, ListNode* list2) {
    // Use a dummy node to simplify the merge
    ListNode* dummy = new ListNode(0);
    ListNode* current = dummy;
    
    while (list1 != nullptr && list2 != nullptr) {
        if (list1->val <= list2->val) {
            current->next = list1;
            list1 = list1->next;
        } else {
            current->next = list2;
            list2 = list2->next;
        }
        current = current->next;
    }
    
    // Attach the remaining nodes
    if (list1 != nullptr) {
        current->next = list1;
    } else {
        current->next = list2;
    }
    
    ListNode* mergedHead = dummy->next;
    delete dummy;
    return mergedHead;
}

bool LinkedListProblems::isPalindrome(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return true;
    }
    
    // Find the middle of the list using slow and fast pointers
    ListNode* slow = head;
    ListNode* fast = head;
    
    while (fast->next != nullptr && fast->next->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    // Reverse the second half
    ListNode* secondHalf = slow->next;
    slow->next = nullptr;
    
    ListNode* prev = nullptr;
    ListNode* current = secondHalf;
    while (current != nullptr) {
        ListNode* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    // Compare first half with reversed second half
    ListNode* firstHalf = head;
    ListNode* reversedSecondHalf = prev;
    
    while (reversedSecondHalf != nullptr) {
        if (firstHalf->val != reversedSecondHalf->val) {
            return false;
        }
        firstHalf = firstHalf->next;
        reversedSecondHalf = reversedSecondHalf->next;
    }
    
    return true;
}

bool LinkedListProblems::hasCycle(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return false;
    }
    
    // Floyd's cycle detection algorithm (tortoise and hare)
    ListNode* slow = head;
    ListNode* fast = head;
    
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        
        if (slow == fast) {
            return true; // Cycle detected
        }
    }
    
    return false; // No cycle
}

