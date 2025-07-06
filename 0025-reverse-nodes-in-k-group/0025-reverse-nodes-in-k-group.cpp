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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummyNode= new ListNode(0,head);
        ListNode* groupPrev=dummyNode;
        while(1){
            ListNode* kth=getkth(groupPrev,k);
            if(kth==NULL)
                break;
            ListNode* groupNext=kth->next;
            ListNode* curr=groupPrev->next;
            ListNode* prev=kth->next;
            while(curr!=groupNext){
                ListNode* temp=curr->next;
                curr->next=prev;
                prev=curr;
                curr=temp;
            }
            ListNode* temp=groupPrev->next;
            groupPrev->next=kth;
            groupPrev=temp;
        }
        return dummyNode->next;
    }

    ListNode* getkth(ListNode* curr,int k){
        while(curr && k>0){
            curr=curr->next;
            k--;
        }
        return curr;
    }
};

