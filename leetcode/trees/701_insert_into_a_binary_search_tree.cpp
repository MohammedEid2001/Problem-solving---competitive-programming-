/*
description:
You are given the root node of a binary search tree (BST) and a value to insert into the tree. Return the root node of the BST after the insertion. It is guaranteed that the new value does not exist in the original BST.

Notice that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion. You can return any of them.
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode *v = new TreeNode(val);
        TreeNode* copy = root;
        if(root == nullptr)return v;
        while(true)
        {
            if(root->val > val)
            {
                if(root->left )
                {
                    root = root->left;
                }
                else{
                    root->left = v;
                    break;
                }
            }
            else
            {
                if(root->right)
                {
                    root = root->right;
                }
                else{
                    root->right = v;
                    break;
                }
            }
        }
        return copy;
    }
};


//cleaner implementation:
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) return new TreeNode(val);
        
        TreeNode* cur = root;
        while (true) {
            if (val < cur->val) {
                if (cur->left) cur = cur->left;
                else { cur->left = new TreeNode(val); return root; }
            } else {
                if (cur->right) cur = cur->right;
                else { cur->right = new TreeNode(val); return root; }
            }
        }
    }
};
