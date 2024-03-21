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
    ListNode* reverseList(ListNode* head) {
        ListNode* ptr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        while (ptr != NULL) {
            next = ptr->next;
            ptr->next = prev;
            prev = ptr;
            ptr = next;
        }
        return prev;
    }
};