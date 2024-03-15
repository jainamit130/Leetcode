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
    int pairSum(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        stack<int> st;
        int ans=0;
        while(fast && fast->next){
            st.push(slow->val);
            fast=fast->next->next;
            cout<<slow->val<<endl;
            slow=slow->next;
        }
        while(slow){
            ans=max(slow->val+st.top(),ans);
            st.pop();
            slow=slow->next;
        }
        return ans;
    }
};