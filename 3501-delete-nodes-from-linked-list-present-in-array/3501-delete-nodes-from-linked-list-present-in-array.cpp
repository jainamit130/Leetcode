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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st(nums.begin(),nums.end());
        ListNode* ptr=head;
        while(ptr && st.find(ptr->val)!=st.end()){
            ptr=ptr->next;
        }

        head=ptr;
        ListNode* prev = head;
        while(ptr->next){
            if(st.find(ptr->next->val)!=st.end()){
                ptr=ptr->next;
            } else {
                prev->next=ptr->next;
                ptr=ptr->next;
                prev=ptr;
            }
        }
        prev->next=ptr->next;
        return head;
    }
};