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
    ListNode *detectCycle(ListNode *head) {
        ListNode *s=head, *f=head;
        while(s && f){
            s=s->next;
            f=f->next;
            if(f) f=f->next;
            if(!f) return NULL;
            if(s==f) break;
        }
        s=head;
        while(1){
            if(s==f) return s;
            s=s->next;
            f=f->next;
        }
    }
};