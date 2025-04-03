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
    using pil = pair<int, ListNode*>;

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        vector<ListNode*> ptrs(k, NULL);
        priority_queue<pil, vector<pil>, greater<pil>> minHeap;
        for (int i = 0; i < k; i++) {
            ptrs[i] = lists[i];
            if(ptrs[i]) minHeap.push({ptrs[i]->val, ptrs[i]});
        }
        ListNode* ans = NULL;
        ListNode* ansPtr = NULL;
        while (!minHeap.empty()) {
            auto [val, ptr] = minHeap.top();
            minHeap.pop();
            if (ans == NULL) {
                ans = new ListNode(val);
                ansPtr = ans;
            } else {
                ansPtr->next = new ListNode(val);
                ansPtr = ansPtr->next;
            }

            ptr = ptr->next;
            if (ptr) {
                minHeap.push({ptr->val, ptr});
            }
        }
        return ans;
    }
};