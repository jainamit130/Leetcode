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
        vector<int> criticalPointsIndexes;
        int i=0;
        ListNode* ptr=head;
        ListNode* prev=NULL;
        int mini=INT_MAX;
        while(ptr){
            if(ptr->next && prev){
                int a=prev->val;
                int b=ptr->val;
                int c=ptr->next->val;
                if((a<b && b>c) || b<a && b<c){
                    if(criticalPointsIndexes.size()>0){
                    mini=min(mini,i-criticalPointsIndexes.back());
                    }
                    criticalPointsIndexes.push_back(i);
                } 
            }
            i++;
            prev=ptr;
            ptr=ptr->next;
        } 
        int maxi=INT_MIN;
        if(criticalPointsIndexes.size()>=2){
            maxi=criticalPointsIndexes.back()-criticalPointsIndexes[0];
        } else {
            return {-1,-1};
        }
        return {mini,maxi};
    }
};