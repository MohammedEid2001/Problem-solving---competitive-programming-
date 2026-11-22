/*
description:
Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxdepth =0;
    int depth(TreeNode* tree)
    {
        if(!tree)return 0;
        int left = depth(tree->left);
        int right = depth(tree->right);
        int d =  left + right;
        if(d > maxdepth)maxdepth= d;
        return max(left,right)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int d = depth(root);
        return maxdepth;
    }
};

//another cleaner approach with better memory optimjzation:
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int best = 0;
        height(root, best);
        return best;
    }
private:
    int height(TreeNode* node, int& best) {
        if (!node) return 0;
        int l = height(node->left,  best);
        int r = height(node->right, best);
        best = max(best, l + r);
        return 1 + max(l, r);
    }
};
