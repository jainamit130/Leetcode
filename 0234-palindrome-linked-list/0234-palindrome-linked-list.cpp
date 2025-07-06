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
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        string s1="";
        while(fast && fast->next){
            s1+=to_string(slow->val);
            slow=slow->next;
            fast=fast->next->next;
        }
        string s2="";
        while(slow){
            s2+=to_string(slow->val);
            slow=slow->next;
        }
        int j=0;
        int i=s1.length()-1;
        if((s1.length()+s2.length())%2!=0){
            j=1;
        }
        while(i>=0 && j<s2.length()){
            if(s1[i]!=s2[j])
                return false;
            i--;j++;
        }
        return true;
    }
};