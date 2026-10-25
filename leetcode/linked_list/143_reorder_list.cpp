/*
description:
You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.
*/


// approach: i used fast slow pointers to find the mid of the list, then cut the list into 2 halves, then reverse the second half , then group them back again

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
    void reorderList(ListNode* head) {
        if(!head || !head->next)return;
        ListNode* slow = head ;
        ListNode* fast = head;
        //int count =0;
        while( fast->next && fast->next->next)
        {
           // ++count;
            slow = slow->next;
            fast = fast->next->next;
        }
        //ListNode* dummy(0);
        ListNode* second = slow->next;
        slow->next =nullptr;
        ListNode* prev = nullptr;
        while(second != nullptr)
        {
            ListNode* nxt= second->next;
            second->next = prev;
             prev = second;
            second = nxt;
        }
        second = prev;
        ListNode* first = head;
        while(second != nullptr)
        {
            ListNode* tmp1 = first->next;
            ListNode* tmp2= second->next;
            first->next = second;
            second->next = tmp1;
            first = tmp1;
            second = tmp2;
        }
    }
};