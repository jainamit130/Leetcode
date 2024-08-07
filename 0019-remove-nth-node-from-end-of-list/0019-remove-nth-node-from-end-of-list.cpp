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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow=head;
        ListNode* fast=head;
        int total=0;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            total+=2;
        }
        if(fast){
            total++;
        }
        if(total==1){
            return NULL;
        }
        int startCount=total-n;
        if(startCount==0){
            return head->next;
        }
        ListNode* ptr=head;
        while(startCount>1){
            startCount--;
            ptr=ptr->next;
        }
        ptr->next=ptr->next->next;
        return head;
    }
};