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


 /*
 
 
[]   []   []  []  []  []  []
[]   []   []  [] => []  []     []   []
[]   []   [] 
 
 */

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return partition(0,lists.size()-1,lists);     
    }

    ListNode* partition(int start,int end,vector<ListNode*>& lists) {
        if(start>end) return NULL;
        if(start==end) return lists[start];
        int mid = (start+end)/2;
        ListNode* list1 = partition(start,mid,lists);
        ListNode* list2 = partition(mid+1,end,lists);
        return merge(list1,list2);
    }

    ListNode* merge(ListNode* list1,ListNode* list2) {
        ListNode* ans = NULL;
        ListNode* ptr = NULL;
        ListNode* ptr1 = list1;
        ListNode* ptr2 = list2;
        while(ptr1 || ptr2) {
            int val = INT_MAX;
            if(ptr1) {
                if(ptr2) {
                    if(ptr1->val<=ptr2->val) {
                        val = min(val,ptr1->val);
                        ptr1 = ptr1->next;
                    } else {
                        val = min(val,ptr2->val);
                        ptr2 = ptr2->next;
                    }
                } else {
                    val = min(val,ptr1->val);
                    ptr1 = ptr1->next;
                }
            } else {
                val = min(val,ptr2->val);
                ptr2 = ptr2->next;
            }

            ListNode* node = new ListNode(val);
            if(!ans) {
                ans = node;
                ptr = node;
            } else {
                ptr->next = node;
                ptr=ptr->next;
            }
        }
        return ans;
    }
};

// class Solution {
// public:
//     using pil = pair<int, ListNode*>;

// public:
//     ListNode* mergeKLists(vector<ListNode*>& lists) {
//         int k = lists.size();
//         vector<ListNode*> ptrs(k, NULL);
//         priority_queue<pil, vector<pil>, greater<pil>> minHeap;
//         for (int i = 0; i < k; i++) {
//             ptrs[i] = lists[i];
//             if(ptrs[i]) minHeap.push({ptrs[i]->val, ptrs[i]});
//         }
//         ListNode* ans = NULL;
//         ListNode* ansPtr = NULL;
//         while (!minHeap.empty()) {
//             auto [val, ptr] = minHeap.top();
//             minHeap.pop();
//             if (ans == NULL) {
//                 ans = new ListNode(val);
//                 ansPtr = ans;
//             } else {
//                 ansPtr->next = new ListNode(val);
//                 ansPtr = ansPtr->next;
//             }

//             ptr = ptr->next;
//             if (ptr) {
//                 minHeap.push({ptr->val, ptr});
//             }
//         }
//         return ans;
//     }
// };