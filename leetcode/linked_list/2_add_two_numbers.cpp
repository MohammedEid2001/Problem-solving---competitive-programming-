/*
description:
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int remainder = 0;
        ListNode* sum = new ListNode(0);
        ListNode* top = sum;
        ListNode* prev =nullptr;
        while(l1 ||l2)
        {
            ListNode* nex = new ListNode(0);
            sum->next = nex;
            int n1 = 0,n2=0;
            
            if(l1)
            {
                n1= l1->val;
                l1=l1->next;
            }
             if(l2)
            {
                n2= l2->val;
                l2=l2->next;
            }
            sum->val +=(n1+n2);
            if(sum->val >=10)
            {
                sum->next->val =  (int)sum->val/10 ;
            }
            sum->val %= 10;
            prev = sum;
            sum= sum->next;
        }
        if(sum->val == 0){prev->next = nullptr;delete sum;}
        return top;
    }
};


//a cleaner version:
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* cur = &dummy;
        int carry = 0;
        while (l1 || l2 || carry) {
            int n1 = l1 ? l1->val : 0;
            int n2 = l2 ? l2->val : 0;
            int total = n1 + n2 + carry;
            cur->next = new ListNode(total % 10);
            carry = total / 10;
            cur = cur->next;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        return dummy.next;
    }
};