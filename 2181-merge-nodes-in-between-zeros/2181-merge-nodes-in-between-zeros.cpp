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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* lt=head;
        int count=0;
        ListNode* root=NULL;
        ListNode* ptr=NULL;
        while(lt!=NULL){
            if(lt->val==0 && count!=0){
                if(!ptr){
                    ptr=new ListNode(count);
                    root=ptr;
                } else {
                    ptr->next=new ListNode(count);
                    ptr=ptr->next;
                }
                count=0;
            } else {
                count+=lt->val;
            }
            lt=lt->next;
        }
        return root;
    }
};