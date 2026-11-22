/*
description:
*/

//approach: we search for the key, if it have no children(leaf node) we just remove it, if it has ony one eft or right, we conntect its parent to it , otherwise , we find the leftmost successor to the right child of it and replace our value with it

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* parent = nullptr;
        TreeNode* cur = root;
        while (cur && cur->val != key) {
            parent = cur;
            cur = (key < cur->val) ? cur->left : cur->right;
        }
        if (!cur) return root;  

        auto splice = [&](TreeNode* child) {
            if (!parent)               root = child;
            else if (parent->left == cur) parent->left  = child;
            else                          parent->right = child;
        };

        if (!cur->left)       splice(cur->right);      
        else if (!cur->right) splice(cur->left);       
        else {
            TreeNode* succParent = cur;
            TreeNode* succ = cur->right;
            while (succ->left) { succParent = succ; succ = succ->left; }
            cur->val = succ->val;
            if (succParent->left == succ) succParent->left  = succ->right;
            else                          succParent->right = succ->right;
        }
        return root;
    }
};
