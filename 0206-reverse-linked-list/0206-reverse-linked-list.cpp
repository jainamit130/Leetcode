class Solution {
public:
    ListNode* ptr;
    ListNode* reverseList(ListNode* head) {
        reverseLL(head,NULL);
        return ptr;
    }

    void reverseLL(ListNode* head,ListNode* prev){
        if(!head){
            ptr=prev;
            return;
        }
        ListNode* temp=head->next;
        head->next=prev;
        reverseLL(temp,head);
        return;
    }
};