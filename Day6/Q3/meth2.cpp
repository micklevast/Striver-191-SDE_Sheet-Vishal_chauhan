#include<bits/stdc++.h>
using namespace std;
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
    int len(ListNode* head){
        ListNode *ptr=head;
        int length=0;
        while(ptr){
            ptr=ptr->next;
            length++;
        }
        return length;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int l=len(head);
        if(l<k)return head;
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* nxt=NULL;
        int i=k;
        while(curr && i>0 ){
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
            i--;
        }
        if (curr) {
            head->next = reverseKGroup(curr, k);
        }
        return prev;
    }

};