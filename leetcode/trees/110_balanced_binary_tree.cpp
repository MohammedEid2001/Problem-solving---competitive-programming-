/*
description:
Given a binary tree, determine if it is height-balanced.
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
    bool balanced = true;
    int height(TreeNode* node)
    {
        if(!node || !balanced)return 0;
        int left = 1+height(node->left);
        int right = 1+ height(node->right);
        if(balanced)balanced = ( abs(left-right)<=1);
        return max(left,right);
    }
    
    bool isBalanced(TreeNode* root) {
        int h = height(root);
        return balanced;
    }
};





// cleaner implementation:
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }
private:
    int height(TreeNode* node) {
        if (!node) return 0;

        int l = height(node->left);
        if (l == -1) return -1;  
        int r = height(node->right);
        if (r == -1) return -1;     
        if (std::abs(l - r) > 1) return -1;   
        return 1 + std::max(l, r);
    }
};
