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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* ptr=list1;
        ListNode* start;
        ListNode* end=list2;
        a--;
        b++;
        while(a){
            ptr=ptr->next;
            a--;
            b--;
        }
        start=ptr;
        while(b){
            ptr=ptr->next;
            b--;
        }
        while(end->next){
            end=end->next;
        }
        start->next=list2;
        end->next=ptr;
        return list1;
    }
};