/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a=NULL, *b=NULL;
        a=headA; b=headB;
        while(a && b){
            if(a==b) return a;
            if(a->next==NULL && b->next==NULL) return NULL;
            if(a->next==NULL) a=headB;
            else a=a->next;
            if(b->next==NULL) b=headA;
            else b=b->next;
        }
        return NULL;
    }
};