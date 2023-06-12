#include<bits/stdc++.h>
using namespace std;
// Floyd’s Cycle-Finding Algorithm // fast slow approach // 2 pointers // "tortoise and the hare algorithm"

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
        if(head==NULL || head->next==NULL)return false;
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast and fast->next){
            fast=fast->next->next;
            slow=slow->next;
            // as the fast is equal to slow ,that means that fast has been turn from anywhere to that to confirm 
            // the  cycle as normally fast is greater than slow,but here as fast==slow then fast have to come back from end ,
            // represet that the cycle was present there
            if(slow==fast)break;
        }
        return slow==fast;
    }
};