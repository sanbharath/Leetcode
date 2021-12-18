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
    
    
    ListNode* appendZeros(ListNode* l1,int zeros){
        
        ListNode* head = new ListNode(0);
        ListNode* temp = head;
    
        
        for(int i=0;i<zeros;i++){
            temp->next = new ListNode(0);
            temp = temp->next;
        }
        
        temp->next = l1;
        
        return head->next;
    
    }
    
    
    int findLength(ListNode* t1){
        int sz = 0;
        while(t1){
            sz++;
            t1 = t1->next;
        }
        return sz;
    }
    
    
    ListNode* findSum(ListNode* l1, ListNode* l2){
        
        ListNode* head = new ListNode(0);
        ListNode* sum = head;
        
        
        int carry = 0;
        
        while(l1 || l2){
            
            if(!l1){
                sum->next = new ListNode((l2->val + carry)%10);
                carry = (l2->val + carry) / 10;
                l2 = l2->next;
            }
            else if(!l2){
                sum->next = new ListNode((l1->val + carry)%10);
                carry = (l1->val + carry) / 10;
                l1 = l1->next;
            }
            else{
                sum->next = new ListNode((l1->val + l2->val + carry)%10);
                carry = (l1->val + l2->val + carry) / 10;
                l1 = l1->next;
                l2 = l2->next;
            }
            
            sum = sum->next;
            
            
        }
        
        if(carry!=0){
            sum->next = new ListNode(carry);
        }
        
    
        return head->next;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        /*
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        
        int sz1 = findLength(t1);    
        int sz2 = findLength(t2);
        
        if(sz1>=sz2){
            l2 = appendZeros(l2, sz1-sz2);
        }
        else{
            l1 = appendZeros(l1, sz2-sz1);
        }
        */
        
        ListNode* sum = findSum(l1, l2);
        
        
        return sum;
    }
};