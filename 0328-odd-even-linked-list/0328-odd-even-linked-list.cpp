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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL || head->next->next==NULL)
            return head;
        ListNode* prev=head;
        ListNode* current=head->next;
        ListNode* copyCurrentHead=current;
        while(prev && current && current->next){
            prev->next=prev->next->next;
            current->next=current->next->next;
            prev=prev->next;
            current=current->next;
        }
        prev->next=copyCurrentHead;
        return head;
    }
};