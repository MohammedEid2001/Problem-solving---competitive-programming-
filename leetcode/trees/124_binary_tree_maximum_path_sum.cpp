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
    int Max(TreeNode* root , int& maxsofar)
    {
        if(!root)return 0;
        int MaxLeft = Max(root->left,maxsofar);
       int  MaxRight= Max(root->right,maxsofar);
        if(root->val > maxsofar)maxsofar= root->val;
        if(MaxLeft +root->val > maxsofar)maxsofar = MaxLeft +root->val;
        if(MaxRight +root->val > maxsofar)maxsofar = MaxRight +root->val;
        if(MaxLeft +root->val + MaxRight> maxsofar)maxsofar = MaxLeft +root->val+MaxRight;
        return max(
            root->val,max(root->val + MaxLeft,MaxRight+ root->val
                         )
            );
    }
    int maxPathSum(TreeNode* root) {
        int maxsofar = INT_MIN;
        Max(root,maxsofar);
        return maxsofar;
    }
};

//optimal solution, we can do dfs normally, and then for current left or right, if its max value is less than 0 we discard it, else we take the nodes value up with us and such

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int best = INT_MIN;
        dfs(root, best);
        return best;
    }
private:
    int dfs(TreeNode* node, int& best) {
        if (!node) return 0;
        int left  = std::max(0, dfs(node->left,  best));
        int right = std::max(0, dfs(node->right, best));
        best = std::max(best, node->val + left + right);
        return node->val + std::max(left, right);
    }
};