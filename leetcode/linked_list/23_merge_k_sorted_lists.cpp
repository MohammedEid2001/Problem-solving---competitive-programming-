/*
description:

*/

//approach: make a priority_queue to always find the min element in O(log(k)) complexity ,for total complexity of O(n * log(k)) where n is the total number of all elements in all lists

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    struct Compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val; 
    }
};
ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> MinQueue;
    for(auto x : lists) if(x)MinQueue.push(x);
    if(MinQueue.empty())return nullptr;    ListNode* sorted = MinQueue.top();
    ListNode* tmp = sorted;
    MinQueue.pop();
    if(sorted->next)MinQueue.push(sorted->next);
    while(!MinQueue.empty())
    {
        ListNode* OnTop= MinQueue.top();
        tmp->next = OnTop;
        tmp =tmp->next;
        MinQueue.pop();
        if(OnTop->next)MinQueue.push(OnTop->next);
    }
    return sorted;
    }
}; 