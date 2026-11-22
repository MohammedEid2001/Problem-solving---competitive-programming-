/*
description:
Given a binary tree root, a node X in the tree is named good if in the path from root to X there are no nodes with a value greater than X.

Return the number of good nodes in the binary tree.
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
    int counter(TreeNode* root, int Max)
    {
        if(!root)return 0;
         Max = max(Max, root ->val);
        return (Max == root->val) + counter(root->left,Max) + counter(root->right,Max);
    }
    int goodNodes(TreeNode* root) {

        return counter(root,-10001);
    }
};