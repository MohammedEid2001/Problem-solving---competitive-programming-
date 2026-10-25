/*
description:
A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.

Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.

Return the head of the copied linked list.

The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.
Your code will only be given the head of the original linked list.

*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        unordered_map<Node*, Node*> oldToNew;
        for (Node* cur = head; cur; cur = cur->next) {
            oldToNew[cur] = new Node(cur->val);
        }

        auto translate = [&](Node* p) -> Node* {
            return p ? oldToNew[p] : nullptr;
        };

        for (Node* cur = head; cur; cur = cur->next) {
            Node* copy = oldToNew[cur];
            copy->next   = translate(cur->next);
            copy->random = translate(cur->random);
        }

        return oldToNew[head];
    }
};


//O(1) space solution, faster, less memory
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        // ---------- Pass 1: weave copies in ----------
        // A -> B -> C   becomes   A -> A' -> B -> B' -> C -> C'
        for (Node* cur = head; cur; cur = cur->next->next) {
            Node* copy   = new Node(cur->val);
            copy->next   = cur->next;   // copy sits right after its original
            cur->next    = copy;
        }

        // ---------- Pass 2: set random on the copies ----------
        // For each original X, its copy is X->next.
        // If X.random = Y, then X->next->random should be Y->next (the copy of Y).
        for (Node* cur = head; cur; cur = cur->next->next) {
            Node* copy   = cur->next;
            copy->random = cur->random ? cur->random->next : nullptr;
        }

        // ---------- Pass 3: un-weave ----------
        // Restore original next pointers, and build the copy list separately.
        Node* newHead = head->next;
        for (Node* cur = head; cur; ) {
            Node* copy       = cur->next;      // the copy of cur
            cur->next        = copy->next;     // restore original: skip the copy
            copy->next       = copy->next ? copy->next->next : nullptr;
            //                                 ^ move past the next original
            cur = cur->next;                   // advance along originals
        }

        return newHead;
    }
};
