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

// always try to put List1 pointer to smaller possible next value for sorting and merging
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL)return list2;
        if(list2==NULL)return list1;
        ListNode* newhead=NULL;
        int flag=0;
        while(list1 && list2){
            if((list1->val)<(list2->val)){
                if(flag==0){
                    newhead=list1;
                    flag=1;
                }
                while(list1->next && list1->next->val<(list2->val)){
                    list1=list1->next;
                    if(list1==NULL){
                        list1->next=list2;
                    }
                }
                ListNode* temp=list1->next;
                list1->next=list2;
                list1=temp;

            }
            else{
                if(flag==0){
                    newhead=list2;
                    flag=1;
                }
                while(list2->next && (list2->next->val)<=(list1->val)){
                    list2=list2->next;
                    if(list2==NULL){
                        list2->next=list1;
                    }
                }
                ListNode* temp=list2->next;
                list2->next=list1;
                list2=temp;
            }
        }
        return newhead;
    }
};