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
    ListNode* rev(ListNode *head){
        ListNode *prev=NULL, *curr=NULL;
        curr=head;
        while(curr){
            ListNode *extra=curr->next;
            curr->next=prev;
            prev=curr;
            curr=extra;
        }
        return prev;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p=rev(l1), *q=rev(l2), *prev=NULL;
        int sum=0, carry=0;
        while(p || q){
            sum=(p?p->val:0)+(q?q->val:0)+carry;
            carry=sum/10;
            sum=sum%10;
            ListNode *curr=new ListNode(sum);
            if(prev) curr->next=prev;
            prev=curr;
            if(p) p=p->next;
            if(q) q=q->next;
        }
        if(carry){
            ListNode *curr=new ListNode(carry);
            curr->next=prev;
            prev=curr;
        }
        
        return prev;
    }
};