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
        ListNode *res=NULL, *prev=NULL;
        while(list1 && list2){
            ListNode *curr=new ListNode();
            if(list1->val <= list2->val){
                curr->val=list1->val;
                list1=list1->next;
            }
            else{
                curr->val=list2->val;
                list2=list2->next;
            }
            if(prev!=NULL) prev->next=curr;
            if(res==NULL) res=curr;
            prev=curr;
           // free(curr);
        }
        while(list1){
            ListNode *curr=new ListNode();
            curr->val=list1->val;
            if(prev!=NULL) prev->next=curr;
            if(res==NULL) res=curr;
            prev=curr;
            list1=list1->next;
            //free(curr);
        }
        while(list2){
            ListNode *curr=new ListNode();
            curr->val=list2->val;
            if(prev!=NULL) prev->next=curr;
            if(res==NULL) res=curr;
            prev=curr;
            list2=list2->next;
           // free(curr);
        }
        return res;
    }
};