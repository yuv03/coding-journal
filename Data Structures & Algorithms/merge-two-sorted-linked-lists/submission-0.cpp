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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;

        ListNode* ans = new ListNode(0);
        ListNode* temp3 = ans;
        

        while(temp1 && temp2){
            if(temp1->val < temp2->val){
                ListNode* temp = new ListNode(temp1->val);
                temp3->next = temp;
                temp3 = temp;
                temp1 = temp1->next;
            }
            else if(temp1->val > temp2->val){
                ListNode* temp = new ListNode(temp2->val);
                temp3->next = temp;
                temp3 = temp;
                temp2 = temp2->next;
            }
            else{
                ListNode* temp = new ListNode(temp2->val);
                ListNode* tempo = new ListNode(temp2->val);
                temp3->next = temp;
                temp3 = temp;
                temp3->next = tempo;
                temp3 = tempo;
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
        }

        while(temp1){
            ListNode* temp = new ListNode(temp1->val);
            temp3->next = temp;
            temp3 = temp;
            temp1 = temp1->next;
        }
        while(temp2){
            ListNode* temp = new ListNode(temp2->val);
            temp3->next = temp;
            temp3 = temp;
            temp2 = temp2->next;
        }
        return ans->next;

    }
};
