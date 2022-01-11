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
    bool hasCycle(ListNode *head) {
        ListNode *s=NULL, *f=NULL;
        s=head; f=head;
        while(s && f){
            s=s->next;
            f=f->next;
            if(f) f=f->next;
            if(!f) return false;
            if(s==f) return true;  
        }
        return false;
    }
};