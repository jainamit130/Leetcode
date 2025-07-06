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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int i=0;
        int first=-1;
        int current=-1;
        ListNode* ptr=head;
        ListNode* prev=NULL;
        int mini=INT_MAX;
        while(ptr){
            if(ptr->next && prev){
                int a=prev->val;
                int b=ptr->val;
                int c=ptr->next->val;
                if((a<b && b>c) || (b<a && b<c)){
                    if(current!=-1){
                        mini=min(mini,i-current);
                    }
                    if(first==-1){
                        first=i;
                    }
                    current=i;
                } 
            }
            i++;
            prev=ptr;
            ptr=ptr->next;
        } 
        
        int maxi=INT_MIN;
        if(first!=-1 && current!=-1 && mini!=INT_MAX){
            maxi=current-first;
        } else {
            return {-1,-1};
        }
        return {mini,maxi};
    }
};