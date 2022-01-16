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
    ListNode *rev(ListNode *head){
        ListNode *prev=NULL, *curr=head, *aage=NULL;
        while(curr){
            aage=curr->next;
            curr->next=prev;
            prev=curr;
            curr=aage;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        ListNode *s=head, *f=head->next;
        while(f && f->next){
            s=s->next;
            f=f->next->next;
        }
        ListNode *temp=rev(s->next);
        while(temp){
            if(head->val!=temp->val) return false;
            head=head->next;
            temp=temp->next;
        }
        return true;
    }
    
};