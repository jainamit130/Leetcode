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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummyNode=new ListNode(0,head);
        unordered_map<int,ListNode*> mp;
        int prefixSum=0;
        mp[0]=dummyNode;
        ListNode* ptr=head;
        while(ptr){
            prefixSum+=ptr->val;
            if(mp.find(prefixSum)==mp.end())
                mp[prefixSum]=ptr;
            else {
                ListNode* start=mp[prefixSum];
                ListNode* temp=start;
                int t=prefixSum;
                while(temp!=ptr){
                    temp=temp->next;
                    t+=temp->val;
                    if(temp!=ptr){
                        mp.erase(t);
                    }
                }
                start->next=ptr->next;
            }
            ptr=ptr->next;
        }
        return dummyNode->next;
    }
};