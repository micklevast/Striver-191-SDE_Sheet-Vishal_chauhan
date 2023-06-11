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
    int total(ListNode *head){
        int i=0;
        while(head){
            head=head->next;
            i++;
        }
        return i;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int ttl=total(head);
        // cout<<"ttl:"<<ttl<<endl;
        ListNode *ans=head;
        if(n==ttl)return ans->next;
        int removedFromfront=ttl-n-1;
        int i=0;
        while(i<removedFromfront){
            i++;
            head=head->next;
        }
        if(head && head->next)
        head->next=head->next->next;
        else if(head)
        head->next=NULL;
        return ans;

    }
};