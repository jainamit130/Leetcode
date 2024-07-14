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
        ListNode* ans=NULL;
        ListNode* ptr=head;
        ListNode* prev=NULL;
        while(ptr){
            int v=ptr->val;
            if(st.find(v)==st.end()){
                if(ans==NULL){
                    ans=ptr;
                    prev=ptr;
                } else {
                    prev->next=ptr;
                    prev=ptr;
                }
            } 
            ptr=ptr->next;
        }
        prev->next=NULL;
        return ans;
    }
};