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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *temp=head;
        int cnt=0;
        while(temp){
            temp=temp->next;
            cnt++;
        }
        n=cnt-n+1;
        ListNode *prev=NULL;
        if(n==1){
            head=head->next;
            return head;
        }
        prev=head;
        n--;
        while(n>1){
            prev=prev->next;
            n--;
        }
        prev->next=prev->next->next;
        return head;
    }
};