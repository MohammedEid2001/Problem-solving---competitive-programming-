/*
description:
Given the head of a linked list, remove the nth node from the end of the list and return its head.
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* leng = head;
        int i = 1;
        while(leng->next){leng = leng->next;++i;}
        i -= (n);
        if (i == 0) {                   
        ListNode* newHead = head->next;
        return newHead;
        }
        leng = head;
        while(--i){leng = leng->next;}
        //ListNode *nex = leng->next;
        leng->next = leng->next->next;

        return head;
    }
};

//one pass solution:
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0, head);       // dummy simplifies head-removal
        ListNode* fast = &dummy;
        ListNode* slow = &dummy;

        // Advance fast so that the gap between fast and slow is n+1 nodes
        for (int i = 0; i <= n; ++i)
            fast = fast->next;

        // Move both until fast falls off the end
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }

        // slow now points to the node *before* the one to delete
        ListNode* toDelete = slow->next;
        slow->next = slow->next->next;
        delete toDelete;

        return dummy.next;
    }
};