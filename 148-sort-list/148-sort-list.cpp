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
    ListNode *midList(ListNode *head){
        ListNode *slow=head, *fast=head->next;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode *mid=midList(head);
        ListNode *left=head, *right=mid->next;
        mid->next=NULL;
        ListNode *l1=sortList(left); 
        ListNode *l2=sortList(right);
        return merge(l1,l2);
    }
    
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode *res= new ListNode(0), *temp=NULL;
        temp=res;
        while(l1 && l2){
            if(l1->val <= l2->val){
                temp->next=l1;
                l1=l1->next;
            }
            else{
                temp->next=l2;
                l2=l2->next;
            }
            temp=temp->next;
        }
        if(l1){
            temp->next=l1;
            // l1=l1->next;
        }
        if(l2){
            temp->next=l2;
            // l2=l2->next;
        }
        return res->next;
    }
};