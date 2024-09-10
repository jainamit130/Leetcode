class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* ptr = head;
        while(ptr && ptr->next){
                int num1= ptr->val;
                int num2= ptr->next->val;
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