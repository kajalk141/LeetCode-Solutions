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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *res=new ListNode(0), *temp=NULL;
        temp=res;
        int sum=0, carry=0;
        while(l1 || l2){
            sum=(l1?l1->val:0)+(l2?l2->val:0)+carry;
            if(sum>9) carry=1;
            else carry=0;
            sum%=10;
            ListNode *curr=new ListNode(sum);
            temp->next=curr;
            temp=temp->next;
            if(l1) l1=l1->next;
            if(l2) l2=l2->next;
        }
        if(carry){
            ListNode *curr=new ListNode(carry);
            temp->next=curr;
        }
        return res->next;
    }
};