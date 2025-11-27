#include "TreeProblems.h"
#include <algorithm>

int TreeProblems::maxDepth(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    
    return 1 + std::max(leftDepth, rightDepth);
}

bool TreeProblems::isSameTree(TreeNode* p, TreeNode* q) {
    // Both are null
    if (p == nullptr && q == nullptr) {
        return true;
    }
    
    // One is null, the other is not
    if (p == nullptr || q == nullptr) {
        return false;
    }
    
    // Values don't match
    if (p->val != q->val) {
        return false;
    }
    
    // Recursively check left and right subtrees
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

TreeNode* TreeProblems::invertTree(TreeNode* root) {
    if (root == nullptr) {
        return nullptr;
    }
    
    // Swap left and right children
    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
    
    // Recursively invert left and right subtrees
    invertTree(root->left);
    invertTree(root->right);
    
    return root;
}

namespace {
    // Helper function to check if two subtrees are mirror images
    bool isMirror(TreeNode* left, TreeNode* right) {
        // Both are null
        if (left == nullptr && right == nullptr) {
            return true;
        }
        
        // One is null, the other is not
        if (left == nullptr || right == nullptr) {
            return false;
        }
        
        // Values must match, and subtrees must be mirrors
        return (left->val == right->val) &&
               isMirror(left->left, right->right) &&
               isMirror(left->right, right->left);
    }
}

bool TreeProblems::isSymmetric(TreeNode* root) {
    if (root == nullptr) {
        return true;
    }
    
    return isMirror(root->left, root->right);
}

namespace {
    // Helper function to build BST from sorted array
    TreeNode* buildBST(const std::vector<int>& arr, int left, int right) {
        if (left > right) {
            return nullptr;
        }
        
        // Choose middle element as root
        int mid = left + (right - left) / 2;
        TreeNode* root = new TreeNode(arr[mid]);
        
        // Recursively build left and right subtrees
        root->left = buildBST(arr, left, mid - 1);
        root->right = buildBST(arr, mid + 1, right);
        
        return root;
    }
}

TreeNode* TreeProblems::sortedArrayToBST(std::vector<int>& nums) {
    return buildBST(nums, 0, nums.size() - 1);
}

bool TreeProblems::hasPathSum(TreeNode* root, int targetSum) {
    if (root == nullptr) {
        return false;
    }
    
    // If we're at a leaf node, check if the remaining sum equals the node value
    if (root->left == nullptr && root->right == nullptr) {
        return root->val == targetSum;
    }
    
    // Recursively check left and right subtrees with reduced sum
    int remainingSum = targetSum - root->val;
    return hasPathSum(root->left, remainingSum) || hasPathSum(root->right, remainingSum);
}

TreeNode* TreeProblems::lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr) {
        return nullptr;
    }
    
    // If both p and q are smaller than root, LCA is in left subtree
    if (p->val < root->val && q->val < root->val) {
        return lowestCommonAncestor(root->left, p, q);
    }
    
    // If both p and q are greater than root, LCA is in right subtree
    if (p->val > root->val && q->val > root->val) {
        return lowestCommonAncestor(root->right, p, q);
    }
    
    // If one is smaller and one is greater, or one equals root, root is the LCA
    return root;
}

