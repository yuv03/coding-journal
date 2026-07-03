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
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        ListNode* sum = new ListNode(0);
        ListNode* temp = sum;
        int carry = 0;

        while(t1 && t2){
            int sumTemp = carry + t1->val + t2->val;
            int rem = sumTemp%10;
            carry = sumTemp/10;
            ListNode* tempVal = new ListNode(rem);
            
            temp->next = tempVal;
            t1 = t1->next;
            t2 = t2->next;
            temp = temp->next;
        }

        while(t1){
            int sumTemp = carry + t1->val;
            int rem = sumTemp%10;
            carry = sumTemp/10;
            ListNode* tempVal = new ListNode(rem);
            temp->next = tempVal;
            t1 = t1->next;
            temp = temp->next;
        }

        while(t2){
            int sumTemp = carry + t2->val;
            int rem = sumTemp%10;
            carry = sumTemp/10;
            ListNode* tempVal = new ListNode(rem);
            temp->next = tempVal;
            t2 = t2->next;
            temp = temp->next;
        }
        if(carry) {
           ListNode* tempVal = new ListNode(carry);
           temp->next = tempVal; 
        }
        return sum->next;
    }
};