/* 
description:
Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.
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
    int preIndex;
    unordered_map<int,int> pos;  

    TreeNode* build(vector<int>& preorder, int inLeft, int inRight) {
        if (inLeft > inRight) return nullptr;

        int rootVal = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootVal);

        int mid = pos[rootVal];

        root->left  = build(preorder, inLeft, mid - 1);
        root->right = build(preorder, mid + 1, inRight);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) return nullptr;

        preIndex = 0;
        pos.clear();
        for (int i = 0; i < (int)inorder.size(); ++i) {
            pos[inorder[i]] = i;
        }

        return build(preorder, 0, (int)inorder.size() - 1);
    }
};
