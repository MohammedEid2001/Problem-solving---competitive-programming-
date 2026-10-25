/*
description:
*/


 /*Definition for singly-linked list.
 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
ListNode(int x) : val(x), next(nullptr) {}
ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr)return nullptr;
        vector< ListNode*> revers;
        while(true && head != nullptr)
        {
            revers.push_back(head);
           head = head->next;
            //if(head == nullptr)break;
        }
        head= revers.back();
        for(int i = revers.size()-1 ; i >=0 ;--i)
        {
            if(i)revers[i]->next = revers[i-1];
            else
            {
                revers[i]->next = nullptr;
            }
        }
        return head;
    }
};

//O(1) space complexity sol:
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        while (head != nullptr) {
            ListNode* nxt = head->next;
            head->next = prev;
            prev = head;
            head = nxt;
        }
        return prev;
    }
};
