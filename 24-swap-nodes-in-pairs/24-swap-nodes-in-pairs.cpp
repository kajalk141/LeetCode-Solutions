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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode *curr=NULL, *prev=NULL, *res=NULL;
        curr=head; res=head->next;
        while(curr){
            if(prev==NULL) prev=curr->next;
            else{
                if(curr->next!=NULL) prev->next=curr->next;
                prev=prev->next;
            }
            if(prev==curr) break;
            if(prev){
                curr->next=prev->next;
                prev->next=curr;
                prev=curr;
                curr=curr->next;
            }
        }
        return res;
    }
};