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
        ListNode *ans=new ListNode();
        ListNode *ansHead=ans;
        
        
        int  carry=0;
        while(l1||l2)
        {
            if(l1)
            {
                carry=carry+l1->val;
                l1=l1->next;
            }
            if(l2)
            {
                 carry=carry+l2->val;
                l2=l2->next;
                
            }
            ans->val=carry%10;
            carry/=10;
            if(l1||l2||carry)
            {
                ans->next=new ListNode(carry);
                ans=ans->next;
            }
             
        }
         return ansHead;
          
    }
};
