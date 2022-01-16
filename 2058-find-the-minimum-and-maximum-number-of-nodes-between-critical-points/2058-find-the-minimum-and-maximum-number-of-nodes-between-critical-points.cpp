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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> points, res(2,-1);
        ListNode *curr=head->next, *prev=head;
        int i=1;
        while(curr->next){
            if((curr->val > prev->val && curr->val > curr->next->val) || (curr->val < prev->val && curr->val < curr->next->val))
                points.push_back(i);
            prev=curr;
            curr=curr->next;
            i++;
        }
        int r=points.size();
        if(r<2) return res;
        res[0]=INT_MAX;
        for(i=1; i<r; i++){
            res[0]=min(res[0],points[i]-points[i-1]);
        }
        res[1]=points[r-1]-points[0];
        return res;
    }
};