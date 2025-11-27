#pragma once
#include "SharedStructs.h"
#include <vector>

class TreeProblems {
public:
    /**
     * @brief Calculate maximum depth of a binary tree
     * 
     * Returns the maximum depth (number of nodes along the longest path from root to leaf).
     * 
     * @param root Root of the binary tree
     * @return Maximum depth of the tree
     * @complexity Time: O(n), Space: O(h) where h is the height of the tree
     */
    static int maxDepth(TreeNode* root);

    /**
     * @brief Check if two binary trees are the same
     * 
     * Determines if two binary trees are structurally identical and have the same node values.
     * 
     * @param p Root of the first tree
     * @param q Root of the second tree
     * @return true if trees are the same, false otherwise
     * @complexity Time: O(n), Space: O(h) where h is the height of the tree
     */
    static bool isSameTree(TreeNode* p, TreeNode* q);

    /**
     * @brief Invert a binary tree
     * 
     * Inverts a binary tree by swapping left and right children of all nodes.
     * 
     * @param root Root of the binary tree
     * @return Root of the inverted tree
     * @complexity Time: O(n), Space: O(h) where h is the height of the tree
     */
    static TreeNode* invertTree(TreeNode* root);

    /**
     * @brief Check if a binary tree is symmetric
     * 
     * Determines if a binary tree is symmetric around its center (mirror of itself).
     * 
     * @param root Root of the binary tree
     * @return true if tree is symmetric, false otherwise
     * @complexity Time: O(n), Space: O(h) where h is the height of the tree
     */
    static bool isSymmetric(TreeNode* root);

    /**
     * @brief Convert sorted array to binary search tree
     * 
     * Converts a sorted integer array to a height-balanced binary search tree.
     * 
     * @param nums Sorted array of integers
     * @return Root of the constructed BST
     * @complexity Time: O(n), Space: O(n) for the tree, O(log n) for recursion
     */
    static TreeNode* sortedArrayToBST(std::vector<int>& nums);

    /**
     * @brief Check if tree has path with target sum
     * 
     * Determines if the tree has a root-to-leaf path such that adding up all the values
     * along the path equals the given target sum.
     * 
     * @param root Root of the binary tree
     * @param targetSum Target sum to find
     * @return true if such path exists, false otherwise
     * @complexity Time: O(n), Space: O(h) where h is the height of the tree
     */
    static bool hasPathSum(TreeNode* root, int targetSum);

    /**
     * @brief Find lowest common ancestor in a BST
     * 
     * Finds the lowest common ancestor (LCA) of two given nodes in a binary search tree.
     * The LCA is the lowest node that has both nodes as descendants.
     * 
     * @param root Root of the BST
     * @param p First node
     * @param q Second node
     * @return Pointer to the LCA node
     * @complexity Time: O(h), Space: O(1)
     */
    static TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q);
};


