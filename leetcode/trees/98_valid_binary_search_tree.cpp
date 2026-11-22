/*
description:
Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys strictly less than the node's key.
The right subtree of a node contains only nodes with keys strictly greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 
*/
bool valid(TreeNode* root,  long lower,  long upper) {
    if (!root) return true;
    if (root->val <= lower || root->val >= upper) return false;
    return valid(root->left,  lower,        root->val) &&
           valid(root->right, root->val,    upper);
}
bool isValidBST(TreeNode* root) {
    return valid(root, LONG_MIN, LONG_MAX);
}


//a way to avoid the [2^31 -1 ] range (the root values equals the min or max) is by making a nullptr refrence

bool valid(TreeNode* root, int* lower, int* upper) {
    if (!root) return true;
    if ((lower && root->val <= *lower) || (upper && root->val >= *upper))
        return false;
    return valid(root->left,  lower, &root->val) &&
           valid(root->right, &root->val, upper);
}
bool isValidBST(TreeNode* root) {
    return valid(root, nullptr, nullptr);
}


