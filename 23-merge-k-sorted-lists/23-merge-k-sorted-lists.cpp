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
typedef pair<int,ListNode*> p; // (val, *curr)
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<p, vector<p>, greater<p>> pq;
        for(int i=0; i<(int)lists.size(); i++){
            ListNode *temp=lists[i];
            if(!temp) continue;
            pq.push({temp->val, temp});
        }
        ListNode *res=NULL, *prev=NULL;
        while(!pq.empty()){
            ListNode *temp=pq.top().second;
            int v=pq.top().first;
            pq.pop();
            if(!prev) prev=new ListNode(v);
            else{
                prev->next=new ListNode(v);
                prev=prev->next;
            }
            if(!res) res=prev;
            temp=temp->next;
            if(temp!=NULL) pq.push({temp->val, temp});
        }
        return res;
    }
};