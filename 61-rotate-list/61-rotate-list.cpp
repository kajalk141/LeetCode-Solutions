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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        int n=0;
        ListNode *tail=head;
        n++;
        while(tail->next){
            tail=tail->next;
            n++;
        }
        n=n-(k%n);
        ListNode *ptr=head;
        n--;
        while(n--){
            ptr=ptr->next;
        }
        tail->next=head;
        head=ptr->next;
        ptr->next=NULL;
        return head;
    }
};