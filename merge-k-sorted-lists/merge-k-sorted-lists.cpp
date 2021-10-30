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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
    
        priority_queue< pair<int,ListNode*>, vector<pair<int,ListNode*>>, greater<pair<int,ListNode*>> > pq;
        for(int i=0;i<lists.size();i++){
            if(lists[i])
                pq.push({lists[i]->val,lists[i]});
        }
        
        ListNode* ans = new ListNode();
        ListNode* head = ans;
        while(pq.size()){
            int val = pq.top().first;
            ListNode* add = pq.top().second;
            pq.pop();
            ListNode* temp = new ListNode(val);
            ans->next = temp;
            ans = ans->next;
            if(add->next){
                pq.push({add->next->val,add->next});
            }
        }
        
        return head->next;
        
    }
};