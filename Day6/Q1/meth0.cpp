#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// /just find the  length of both list then traverse greater len list to it's diff then traverse simultaneouly untill found equal node
// TC:O(m+n)
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1=0,len2=0;
        ListNode *p=headA,*q=headB;
        while(p){
            len1++;
            p=p->next;
        }
        while(q){
            len2++;
            q=q->next;
        }
        p=headA,q=headB;
        if(len1>len2){
            int diff=len1-len2;
            while(diff){
                diff--;
                p=p->next;
            }
        }
        else{
            int d=len2-len1;
            while(d){
                d--;
                q=q->next;
            }
        }
        while(p!=q){
            p=p->next;q=q->next;
        }
        return q;
    }
};