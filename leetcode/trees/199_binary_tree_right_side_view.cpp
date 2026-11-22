/*
description:


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
  /*  void arrange(, TreeNode* root, int level, int shadow)
    {
        if(!root)return;
        val.push_back({root->val,});
        if(root->left)arrange
    }*/
    vector<int> rightSideView(TreeNode* root) {
        vector<int> right;
        if(!root) return right;
        queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();   
        right.push_back(q.back()->val);
        for (int i = 0; i < size; ++i) {
            TreeNode* node = q.front();
            q.pop();
            if (node->left)  q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
        
        return right;
    }
};
