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
    ListNode* doubleIt(ListNode* head) {
        ListNode* ptr=head;
        stack<int> st;
        while(ptr){
            st.push(ptr->val);
            ptr=ptr->next;
        }
        ListNode* ans=NULL;
        int carry=0;
        while(!st.empty()){
            int digit=st.top();
            st.pop();
            digit=(digit*2)+carry;
            int t=digit%10;
            ListNode* node=new ListNode(t);
            digit/=10;
            if(digit){
                carry=1;
            } else
                carry=0;
            node->next=ans;
            ans=node;
        }
        if(carry)
            ans=new ListNode(carry,ans);
        return ans;
    }
};