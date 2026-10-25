/*
description:
*/


//destructive methofd: connect all visited values to a dummy, if the dummy was visited again, then we have a loop.
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode Dumm(-1);
        while(head !=nullptr && head->next != nullptr)
        {
            if(head->next ==&Dumm)
            {
                return true;
            }
            ListNode* tmp = head->next;
            head->next = &Dumm;
            head = tmp;
        }

        return false;
    }
};


//better approach: slow fast pointers(floyd's cycle detection) where we move the slow by 1 and fast by 2 , and they will eventually meet if theres a cycle:

bool hasCycle(ListNode *head) {
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {      // fast hits the end → no cycle
        slow = slow->next;            // 1 step
        fast = fast->next->next;      // 2 steps
        if (slow == fast) return true; // caught up → cycle
    }
    return false;
}