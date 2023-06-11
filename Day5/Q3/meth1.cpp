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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ans=new ListNode(0);
        ListNode* myHead=NULL;int flag=0;
        if(list1==NULL)return list2;
        if(list2==NULL)return list1;
        while(list1 && list2){
            if(list1->val < list2->val){
                ans->next=list1;
                ans=ans->next;
                list1=list1->next;
                if(myHead==NULL)myHead=ans;
            }
            else{
                ans->next=list2;
                ans=ans->next;
                list2=list2->next;
                if(myHead==NULL)myHead=ans;
            }
        }
        while(list1){
            ans->next=list1;
            list1=list1->next;
            ans=ans->next;
        }
        while(list2){
            ans->next=list2;
            list2=list2->next;
            ans=ans->next;
        }
        return myHead;
    }
};