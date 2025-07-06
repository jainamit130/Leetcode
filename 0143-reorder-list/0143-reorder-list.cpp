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
    void reorderList(ListNode* head) {
        stack<ListNode*> s;
        ListNode* first = head;
        ListNode* lastNode = head;
        while (lastNode->next != NULL && lastNode->next->next != NULL) {
            first = first->next;
            lastNode = lastNode->next->next;
        }
        first=first->next;
        while(first){
            s.push(first);
            first=first->next;
        }
        first = head;
        while (!s.empty()) {
            lastNode = s.top();
            s.pop();
            ListNode* temp = first->next;
            first->next = lastNode;
            lastNode->next = temp;
            first = temp;
        }
        first->next=NULL;
        return;
    }
};