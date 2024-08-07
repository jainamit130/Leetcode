class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL)   return NULL;
        ListNode *start = head, *delValue = head;
        if(start->next == NULL && n==1) return NULL;
        while(n) {
            start = start->next;
            n--;
        }
        if(start == NULL) return delValue->next;
        while(start->next) {
            start = start->next;
            delValue = delValue->next;
        }
        delValue->next = delValue->next->next;
        return head; 
    }
};