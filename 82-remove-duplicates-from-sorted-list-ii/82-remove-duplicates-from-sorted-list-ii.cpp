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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *res=new ListNode(0);
        res->next=head;
        ListNode *c=res;
        int duplicate;
        while(c->next && c->next->next){
            if(c->next->val == c->next->next->val){
                duplicate=c->next->val;
                while(c->next && c->next->val == duplicate)
                    c->next=c->next->next;
            }
            else c=c->next;
        }
        return res->next;
    }
};