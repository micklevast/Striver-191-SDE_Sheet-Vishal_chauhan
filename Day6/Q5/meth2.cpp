
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* ans=NULL;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(fast==slow)break;
        }
        if(slow==fast && slow &&  slow->next){
        ListNode *ptr=head;
        while(ptr!=slow){
            slow=slow->next;
            ptr=ptr->next;
        }
        return slow;
    }
        return NULL;
    }
};