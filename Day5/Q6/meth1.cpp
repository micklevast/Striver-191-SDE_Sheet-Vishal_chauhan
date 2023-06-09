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
// TC=O(N)
class Solution {
public:
    void deleteNode(ListNode* node) {
        while(node->next){
            node->val=node->next->val;
            if(node->next->next==NULL){
                node->next=NULL;break;
            }
            node=node->next;
        }

    }
};