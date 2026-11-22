/*
description:
Given the root of a binary tree, return the preorder traversal of its nodes' values.

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
    void helper(vector<int>&a,TreeNode* n)
    {
        if(!n)return;
        a.push_back(n->val);
        helper(a,n->left);
        helper(a,n->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        helper(preorder,root);
        return preorder;
    }
};
