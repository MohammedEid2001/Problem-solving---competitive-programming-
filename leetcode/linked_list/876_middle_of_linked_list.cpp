/*
description:
Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.
*/


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
    ListNode* middleNode(ListNode* head) {
        ListNode* copyhead = head;
        int mx = 0;
        //head = head->next;
        while(head != nullptr)
        {
            head = head->next;
            ++mx;
        }
        mx /=2;
        for(int i = 0 ; i<mx ;++i)copyhead = copyhead->next;
        return copyhead;
    }
};
