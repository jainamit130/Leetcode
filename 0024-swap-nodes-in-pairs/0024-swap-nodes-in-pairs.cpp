class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* prev = NULL;
        ListNode* curr = head;
        int count = 0;

        while(count<2){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        head->next = swapPairs(curr);
        return prev;
    }
};