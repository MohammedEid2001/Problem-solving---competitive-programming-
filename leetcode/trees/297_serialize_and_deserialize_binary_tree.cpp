/*
description:
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

Clarification: The input/output format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    string a;
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        a.clear();
        if(!root)return a;
        vector<TreeNode*> x;
        x.push_back(root);
        a += to_string(root->val);
        string comma =",";
        a+=comma;
        int idx = 0;
        while(idx < x.size())
        {
            root = x[idx++];
            if(root->left)
            {
                x.push_back(root->left);
                a += to_string(root->left->val);
                a += comma;
            }
            else{
                a+= "#,";
            }
            if(root->right)
            {
                x.push_back(root->right);
                a += to_string(root->right->val);
                a += comma;
            }
            else{
                a+= "#,";
            }
        }
        return a;
    }
    int GetNode(string &a, int start, int end)
    {
        if(a[start] == '#')return -1001;
        int s = 0;
        for(int i =start,mult =1; i<end;++i, mult *=10)
        {
            s*=mult;
            s += (a[i]-'0');
        }
        return s;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
    if (data.empty()) return nullptr;

    // parse tokens
    vector<string> t;
    string cur;
    for (char c : data) {
        if (c == ',') { t.push_back(cur); cur.clear(); }
        else cur += c;
    }
    if (t.empty() || t[0] == "#") return nullptr;

    TreeNode* root = new TreeNode(stoi(t[0]));
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < (int)t.size()) {
        TreeNode* node = q.front(); q.pop();

        if (i < (int)t.size() && t[i] != "#") {
            node->left = new TreeNode(stoi(t[i]));
            q.push(node->left);
        }
        ++i;

        if (i < (int)t.size() && t[i] != "#") {
            node->right = new TreeNode(stoi(t[i]));
            q.push(node->right);
        }
        ++i;
    }
    return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));



//cleaner implementation:
class Codec {
    static void ser(TreeNode* n, string& out) {
        if (!n) { out += "#,"; return; }
        out += to_string(n->val);
        out += ',';
        ser(n->left,  out);
        ser(n->right, out);
    }

    static TreeNode* deser(const string& s, size_t& i) {
        if (s[i] == '#') { i += 2; return nullptr; }   

        bool neg = (s[i] == '-');
        if (neg) ++i;

        int val = 0;
        while (s[i] != ',') { val = val * 10 + (s[i] - '0'); ++i; }
        ++i;                                          

        TreeNode* n = new TreeNode(neg ? -val : val);
        n->left  = deser(s, i);
        n->right = deser(s, i);
        return n;
    }

public:
    string serialize(TreeNode* root) {
        string out;
        out.reserve(4096);          
        ser(root, out);
        return out;
    }

    TreeNode* deserialize(string data) {
        size_t i = 0;
        return deser(data, i);
    }
};