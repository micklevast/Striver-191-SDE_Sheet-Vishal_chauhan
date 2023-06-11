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

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // l1=reverse(l1);
        // l2=reverse(l2);
        ListNode *ans=new ListNode(0);
        ListNode *newH=NULL;
        int c=0;
        while(l1 && l2){
            int sum=l1->val+l2->val;
            l1=l1->next ;l2=l2->next;
            sum+=c;
            int r=sum%10;
            int cc=sum/10;
            c=cc;
            ans->next=new ListNode(r);
            ans=ans->next;
            if(newH==NULL)newH=ans;
        }
        while(l1){
            int sum=l1->val;
            l1=l1->next ;
            sum+=c;
            int r=sum%10;
            int cc=sum/10;
            c=cc;
            ans->next=new ListNode(r);
            ans=ans->next;
            if(newH==NULL)newH=ans;            
        }
        while(l2){
            int sum=l2->val;
            l2=l2->next;
            sum+=c;
            int r=sum%10;
            int cc=sum/10;
            c=cc;
            ans->next=new ListNode(r);
            ans=ans->next;
            if(newH==NULL)newH=ans;            
        } 
        if(c){            
            ans->next=new ListNode(c);
            ans=ans->next;            
        }   
        return newH;    
    }
};