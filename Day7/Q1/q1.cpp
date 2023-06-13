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
    int len(ListNode *head){
        int l=0;
        if(head==NULL)return l;
        while(head){
            head=head->next;
            l++;
        }
        return l;
    }
    // O(N)
    ListNode* rotateRight(ListNode* head, int k) {
        int l=len(head);
        if(l==0 ||k==0 || l==1 || l==k || k%l==0)return head;

        int m=l-(k%l);
        ListNode *h=head;
        m--;
        while(m>0){  //move towrord k-1 times
            h=h->next;
            m--;
        }
        ListNode *ptr=h->next;
        ListNode *nh=ptr; //next val is our new head
        h->next=NULL;
        while(ptr && ptr->next){
            ptr=ptr->next;
        }
        if(ptr )
        ptr->next=head; //pointing the last node to first node
        head=nh; //making new head
        return head;
    }
};