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
     bool flag = false;
    ListNode *find(ListNode *head,int k,int &count){
        if(head==NULL)return head;

        ListNode* temp=find(head->next,k,count);

        // when backtrack then increase count value and find the K+1th node from the last of LL
        count++;
        if(count==k+1){
            flag = true;
            head->next=head->next->next;
        }
        return head;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        int count=0;
        
        ListNode *Nhead=find(head,n,count);
        return flag ?  Nhead : head->next;
    }
};