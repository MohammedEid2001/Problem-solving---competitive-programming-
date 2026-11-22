/*
description:
Given the root of a binary tree, invert the tree, and return its root.
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
    void invert(TreeNode* tmp)
    {
        if(!tmp)return;
        swap(tmp->left,tmp->right);
        invert(tmp->left);
        invert(tmp->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        TreeNode* tmp= root;
        invert(tmp);
        return root;
    }
};
