/*
description:
Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.
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
 
 //O(n) space + time compelxity solution
class Solution {
public:

    void Sort(vector<int> &x , TreeNode* cur)
    {
        if(!cur)return;
        Sort(x,cur->left);
        x.push_back(cur->val);
        Sort(x,cur->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> sorted;
        Sort(sorted,root);
        return sorted[k-1];
    }
};

//more optimized O(k+h) time and O(h) memory solution (h is height of tree)

int kthSmallest(TreeNode* root, int k) {
    stack<TreeNode*> st;
    TreeNode* cur = root;
    while (cur || !st.empty()) {
        while (cur) { st.push(cur); cur = cur->left; }
        cur = st.top(); st.pop();
        if (--k == 0) return cur->val;
        cur = cur->right;
    }
    return -1; // unreachable for valid input
}


