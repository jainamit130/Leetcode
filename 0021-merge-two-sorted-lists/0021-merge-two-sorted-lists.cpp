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
        ListNode* ptr = NULL;
        ListNode* ans = NULL;
        ListNode* ptr1 = list1;
        ListNode* ptr2 = list2;
        while(ptr1 || ptr2) {
            int val = -101;
            if(ptr1) {
                if(ptr2 && ptr2->val <= ptr1->val) {
                    val = ptr2->val;
                    ptr2 = ptr2->next;
                } else {
                    val = ptr1->val;
                    ptr1 = ptr1->next;
                }
            } else {
                val = ptr2->val;
                ptr2 = ptr2->next;
            }

            if(ans==NULL) {
                ptr = new ListNode(val);
                ans = ptr;
            } else {
                ListNode* temp = new ListNode(val);
                ptr->next = temp;
                ptr = ptr->next;
            }
        }
        return ans;
    }
};