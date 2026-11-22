/*
description:
Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.

A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. The tree tree could also be considered as a subtree of itsel
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

    bool same(TreeNode* a, TreeNode* b)
    {
        if(!a || !b)return a == b;
        return (a->val == b->val )
&& same(a->left,b->left) && same(a->right , b->right); 
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        //if(!root)return false;
        bool cur =same(root,subRoot);
        if(cur)return true;
        
        bool left =root->left?isSubtree(root->left, subRoot):0;
        bool right = root->right?isSubtree(root->right,subRoot):0;
        return left || right;
    }
};


//another approach i wanted to try is KMP for O(m+n) complexity, but somehow, the first approach thats got O(n.m) got beats 100%,99% in both time and memory repsecitvely, while the kmp results werent even close to beating 10% in both, and i think thats because of the number of memory assignments that we do in the kmp, and that we are comparing the average time complexity of first approach to worst case of KMP

class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        constexpr int NULL_MARK = INT_MIN;  // safe for 572: values ∈ [-1e5, 1e5]
        std::vector<int> text, pat;
        serialize(root,    text, NULL_MARK);
        serialize(subRoot, pat,  NULL_MARK);
        return contains(text, pat);
    }
private:
    void serialize(TreeNode* n, std::vector<int>& out, int nullMark) {
        if (!n) { out.push_back(nullMark); return; }
        out.push_back(n->val);
        serialize(n->left,  out, nullMark);
        serialize(n->right, out, nullMark);
    }

    bool contains(const std::vector<int>& text, const std::vector<int>& pat) {
        int m = pat.size(), n = text.size();
        if (m == 0) return true;

        std::vector<int> pi(m, 0);
        for (int i = 1, k = 0; i < m; ++i) {
            while (k > 0 && pat[i] != pat[k]) k = pi[k - 1];
            if (pat[i] == pat[k]) ++k;
            pi[i] = k;
        }
        for (int i = 0, k = 0; i < n; ++i) {
            while (k > 0 && text[i] != pat[k]) k = pi[k - 1];
            if (text[i] == pat[k]) ++k;
            if (k == m) return true;
        }
        return false;
    }
};
