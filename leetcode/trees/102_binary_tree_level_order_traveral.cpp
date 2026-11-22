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

    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)return {};        vector< vector<int>> breadth;
        vector< pair<TreeNode*,int>> Stack;
        Stack.push_back({root,0});
        int index =0;
        while(index < Stack.size())
        {
            root = Stack[index].first;
            int level = Stack[index++].second;
            if(breadth.size()== level)breadth.push_back({});
            breadth[level].push_back(root->val);
            
            if(root->left)Stack.push_back({root->left,level+1});
            if(root->right)Stack.push_back({root->right,level+1});
        }
        return breadth;
    }
};

// a cleaner approach emptying the vector that contains the level each time we finish it to lowwer space needed :

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if (!root) return result;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();          // snapshot current level width
        vector<int> level;
        level.reserve(size);
        for (int i = 0; i < size; ++i) {
            TreeNode* node = q.front(); q.pop();
            level.push_back(node->val);
            if (node->left)  q.push(node->left);
            if (node->right) q.push(node->right);
        }
        result.push_back(std::move(level));
    }
    return result;
}
