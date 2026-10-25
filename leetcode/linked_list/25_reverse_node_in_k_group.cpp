/*
description:
*/


class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* fast = head;
        ListNode* slow = head;
        bool first = true;
        ListNode* prevGroupTail = nullptr;
        int current = 1;

        while (fast) {
            ListNode* after = fast->next;

            if (current == k) {
                ListNode* oldGroupHead = slow;
                ListNode* prev = nullptr;
                ListNode* curr = slow;

                while (curr != after) {
                    ListNode* nxt = curr->next;
                    curr->next = prev;
                    prev = curr;
                    curr = nxt;
                }

                if (first) {
                    head = prev;
                    first = false;
                } else {
                    prevGroupTail->next = prev;
                }

                oldGroupHead->next = after;
                prevGroupTail = oldGroupHead;

                current = 1;
                fast = after;
                slow = after;
                continue;
            } else {
                ++current;
            }

            fast = fast->next;
        }

        return head;
    }
};


//cleaner version:
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* groupPrev = &dummy;

        while (true) {
            // Find the kth node of the current group
            ListNode* kth = groupPrev;
            for (int i = 0; i < k && kth; ++i) {
                kth = kth->next;
            }

            // Fewer than k nodes left
            if (!kth) break;

            ListNode* groupNext = kth->next;
            ListNode* oldHead = groupPrev->next;

            // Reverse the group
            ListNode* prev = nullptr;
            ListNode* curr = oldHead;

            while (curr != groupNext) {
                ListNode* nxt = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nxt;
            }

            // Connect previous part to reversed group
            groupPrev->next = prev;

            // Connect old head, now the tail, to the next group
            oldHead->next = groupNext;

            // Move groupPrev to the tail of the reversed group
            groupPrev = oldHead;
        }

        return dummy.next;
    }
};