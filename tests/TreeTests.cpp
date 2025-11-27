#include <gtest/gtest.h>
#include "TreeProblems.h"
#include <vector>
#include <queue>
#include <climits>
#include <cstdint>

// Helper function to create a binary tree from a level-order vector
// Uses -1 or null to represent missing nodes (LeetCode style)
TreeNode* createTree(const std::vector<int>& values) {
    if (values.empty() || values[0] == -1) {
        return nullptr;
    }
    
    TreeNode* root = new TreeNode(values[0]);
    std::queue<TreeNode*> q;
    q.push(root);
    
    int i = 1;
    while (!q.empty() && i < values.size()) {
        TreeNode* node = q.front();
        q.pop();
        
        // Left child
        if (i < values.size() && values[i] != -1) {
            node->left = new TreeNode(values[i]);
            q.push(node->left);
        }
        i++;
        
        // Right child
        if (i < values.size() && values[i] != -1) {
            node->right = new TreeNode(values[i]);
            q.push(node->right);
        }
        i++;
    }
    
    return root;
}

// Helper function to delete a binary tree
void deleteTree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

// Helper function to convert tree to level-order vector (for comparison)
std::vector<int> treeToVector(TreeNode* root) {
    std::vector<int> result;
    if (root == nullptr) {
        return result;
    }
    
    std::queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        
        if (node != nullptr) {
            result.push_back(node->val);
            q.push(node->left);
            q.push(node->right);
        } else {
            result.push_back(-1);
        }
    }
    
    // Remove trailing -1s
    while (!result.empty() && result.back() == -1) {
        result.pop_back();
    }
    
    return result;
}

// Helper function to find a node with a specific value
TreeNode* findNode(TreeNode* root, int val) {
    if (root == nullptr) {
        return nullptr;
    }
    
    if (root->val == val) {
        return root;
    }
    
    TreeNode* left = findNode(root->left, val);
    if (left != nullptr) {
        return left;
    }
    
    return findNode(root->right, val);
}

// 1. Maximum Depth of Binary Tree
TEST(TreeTests, MaxDepth) {
    // Test case: [3,9,20,null,null,15,7] -> depth 3
    TreeNode* root = createTree({3, 9, 20, -1, -1, 15, 7});
    EXPECT_EQ(TreeProblems::maxDepth(root), 3);
    deleteTree(root);
    
    // Test case: [1,null,2] -> depth 2
    root = createTree({1, -1, 2});
    EXPECT_EQ(TreeProblems::maxDepth(root), 2);
    deleteTree(root);
    
    // Test case: [] -> depth 0
    root = nullptr;
    EXPECT_EQ(TreeProblems::maxDepth(root), 0);
    
    // Test case: [1] -> depth 1
    root = createTree({1});
    EXPECT_EQ(TreeProblems::maxDepth(root), 1);
    deleteTree(root);
}

// 2. Same Tree
TEST(TreeTests, IsSameTree) {
    // Test case: [1,2,3] and [1,2,3] -> true
    TreeNode* p = createTree({1, 2, 3});
    TreeNode* q = createTree({1, 2, 3});
    EXPECT_TRUE(TreeProblems::isSameTree(p, q));
    deleteTree(p);
    deleteTree(q);
    
    // Test case: [1,2] and [1,null,2] -> false
    p = createTree({1, 2});
    q = createTree({1, -1, 2});
    EXPECT_FALSE(TreeProblems::isSameTree(p, q));
    deleteTree(p);
    deleteTree(q);
    
    // Test case: [1,2,1] and [1,1,2] -> false
    p = createTree({1, 2, 1});
    q = createTree({1, 1, 2});
    EXPECT_FALSE(TreeProblems::isSameTree(p, q));
    deleteTree(p);
    deleteTree(q);
    
    // Test case: [] and [] -> true
    p = nullptr;
    q = nullptr;
    EXPECT_TRUE(TreeProblems::isSameTree(p, q));
}

// 3. Invert Binary Tree
TEST(TreeTests, InvertTree) {
    // Test case: [4,2,7,1,3,6,9] -> [4,7,2,9,6,3,1]
    TreeNode* root = createTree({4, 2, 7, 1, 3, 6, 9});
    TreeNode* inverted = TreeProblems::invertTree(root);
    
    // Check that left and right are swapped
    EXPECT_EQ(inverted->val, 4);
    EXPECT_EQ(inverted->left->val, 7);
    EXPECT_EQ(inverted->right->val, 2);
    EXPECT_EQ(inverted->left->left->val, 9);
    EXPECT_EQ(inverted->left->right->val, 6);
    EXPECT_EQ(inverted->right->left->val, 3);
    EXPECT_EQ(inverted->right->right->val, 1);
    
    deleteTree(inverted);
    
    // Test case: [2,1,3] -> [2,3,1]
    root = createTree({2, 1, 3});
    inverted = TreeProblems::invertTree(root);
    EXPECT_EQ(inverted->left->val, 3);
    EXPECT_EQ(inverted->right->val, 1);
    deleteTree(inverted);
    
    // Test case: [] -> []
    root = nullptr;
    inverted = TreeProblems::invertTree(root);
    EXPECT_EQ(inverted, nullptr);
}

// 4. Symmetric Tree
TEST(TreeTests, IsSymmetric) {
    // Test case: [1,2,2,3,4,4,3] -> true
    TreeNode* root = createTree({1, 2, 2, 3, 4, 4, 3});
    EXPECT_TRUE(TreeProblems::isSymmetric(root));
    deleteTree(root);
    
    // Test case: [1,2,2,null,3,null,3] -> false
    root = createTree({1, 2, 2, -1, 3, -1, 3});
    EXPECT_FALSE(TreeProblems::isSymmetric(root));
    deleteTree(root);
    
    // Test case: [1] -> true
    root = createTree({1});
    EXPECT_TRUE(TreeProblems::isSymmetric(root));
    deleteTree(root);
    
    // Test case: [] -> true
    root = nullptr;
    EXPECT_TRUE(TreeProblems::isSymmetric(root));
    
    // Test case: [1,2,2,2,-1,2] -> false
    root = createTree({1, 2, 2, 2, -1, 2});
    EXPECT_FALSE(TreeProblems::isSymmetric(root));
    deleteTree(root);
}

// Helper function to verify BST property
bool isValidBST(TreeNode* root, long long minVal, long long maxVal) {
    if (root == nullptr) {
        return true;
    }
    
    if (root->val <= minVal || root->val >= maxVal) {
        return false;
    }
    
    return isValidBST(root->left, minVal, root->val) &&
           isValidBST(root->right, root->val, maxVal);
}

// 5. Convert Sorted Array to Binary Search Tree
TEST(TreeTests, SortedArrayToBST) {
    // Test case: [-10,-3,0,5,9]
    std::vector<int> nums = {-10, -3, 0, 5, 9};
    TreeNode* root = TreeProblems::sortedArrayToBST(nums);
    
    // Verify it's a valid BST
    EXPECT_TRUE(isValidBST(root, INT64_MIN, INT64_MAX));
    
    // Verify depth is balanced (should be 3 for 5 elements)
    int depth = TreeProblems::maxDepth(root);
    EXPECT_LE(depth, 3); // Height-balanced
    
    // Verify all values are present
    EXPECT_EQ(root->val, 0); // Root should be middle element
    
    deleteTree(root);
    
    // Test case: [1,3]
    nums = {1, 3};
    root = TreeProblems::sortedArrayToBST(nums);
    EXPECT_TRUE(isValidBST(root, INT64_MIN, INT64_MAX));
    EXPECT_LE(TreeProblems::maxDepth(root), 2);
    deleteTree(root);
    
    // Test case: []
    nums = {};
    root = TreeProblems::sortedArrayToBST(nums);
    EXPECT_EQ(root, nullptr);
    
    // Test case: [0]
    nums = {0};
    root = TreeProblems::sortedArrayToBST(nums);
    EXPECT_EQ(root->val, 0);
    EXPECT_EQ(root->left, nullptr);
    EXPECT_EQ(root->right, nullptr);
    deleteTree(root);
}

// 6. Path Sum
TEST(TreeTests, HasPathSum) {
    // Test case: [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22 -> true
    // Path: 5 -> 4 -> 11 -> 2 = 22
    TreeNode* root = createTree({5, 4, 8, 11, -1, 13, 4, 7, 2, -1, -1, -1, 1});
    EXPECT_TRUE(TreeProblems::hasPathSum(root, 22));
    deleteTree(root);
    
    // Test case: [1,2,3], targetSum = 5 -> false
    root = createTree({1, 2, 3});
    EXPECT_FALSE(TreeProblems::hasPathSum(root, 5));
    deleteTree(root);
    
    // Test case: [], targetSum = 0 -> false
    root = nullptr;
    EXPECT_FALSE(TreeProblems::hasPathSum(root, 0));
    
    // Test case: [1,2], targetSum = 1 -> false (must be root-to-leaf)
    root = createTree({1, 2});
    EXPECT_FALSE(TreeProblems::hasPathSum(root, 1));
    deleteTree(root);
    
    // Test case: [1,2], targetSum = 3 -> true
    root = createTree({1, 2});
    EXPECT_TRUE(TreeProblems::hasPathSum(root, 3));
    deleteTree(root);
}

// 7. Lowest Common Ancestor of a Binary Search Tree
TEST(TreeTests, LowestCommonAncestor) {
    // Test case: [6,2,8,0,4,7,9,null,null,3,5], p=2, q=8 -> 6
    TreeNode* root = createTree({6, 2, 8, 0, 4, 7, 9, -1, -1, 3, 5});
    TreeNode* p = findNode(root, 2);
    TreeNode* q = findNode(root, 8);
    TreeNode* lca = TreeProblems::lowestCommonAncestor(root, p, q);
    EXPECT_EQ(lca->val, 6);
    deleteTree(root);
    
    // Test case: [6,2,8,0,4,7,9,null,null,3,5], p=2, q=4 -> 2
    root = createTree({6, 2, 8, 0, 4, 7, 9, -1, -1, 3, 5});
    p = findNode(root, 2);
    q = findNode(root, 4);
    lca = TreeProblems::lowestCommonAncestor(root, p, q);
    EXPECT_EQ(lca->val, 2);
    deleteTree(root);
    
    // Test case: [2,1], p=2, q=1 -> 2
    root = createTree({2, 1});
    p = findNode(root, 2);
    q = findNode(root, 1);
    lca = TreeProblems::lowestCommonAncestor(root, p, q);
    EXPECT_EQ(lca->val, 2);
    deleteTree(root);
}

