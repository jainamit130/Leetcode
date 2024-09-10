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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* ptr = head;
        while(ptr && ptr->next){
            // is middle?
                int num1= ptr->val;
                int num2= ptr->next->val;
                // find GCD of num1 and num2
                // What is GCD?
                /*
                    18 =  
                    10 =
                    10 -> 1 which ever divides both
                
                */
                int gcd = min(num1,num2);
                for(;gcd>=1;gcd--){
                    if(num1%gcd==0 && num2%gcd==0){
                        break;
                    }
                }
                ListNode* gcdNode = new ListNode(gcd);
                ListNode* temp = ptr->next;
                ptr->next=gcdNode;
                gcdNode->next = temp;
                ptr=temp;
        }
        return head;
    }
};