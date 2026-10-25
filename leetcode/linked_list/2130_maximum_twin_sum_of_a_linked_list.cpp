/*
description:

*/

//store the pointers in a vector and then go around them


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
    int pairSum(ListNode* head) {
       // ListNode* reverse = head;
       // ListNode* tmp = head;
        int counter = 0;
        int MaxSum= 0;
        vector< ListNode*> nums;
        nums.push_back(head);
        while(head->next != nullptr){
            head= head->next;
            nums.push_back(head);
            //++counter;                 
                                    }
        for(int i = 0,j = nums.size()-1; i <j;++i,--j)
        {
            int tmp =nums[i]->val + nums[j]->val;
            if(tmp >MaxSum)MaxSum=tmp;
        }
        return MaxSum;
    }
};