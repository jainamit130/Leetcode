class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* ptr = head;
        while(ptr && ptr->next){
                int num1= ptr->val;
                int num2= ptr->next->val;
                int gcd_val = gcd(num1,num2); 
                // min(num1,num2);
                // for(;gcd_val>=1;gcd_val--){
                //     if(num1%gcd_val==0 && num2%gcd_val==0){
                //         break;
                //     }
                // }
                ListNode* gcdNode = new ListNode(gcd_val);
                ListNode* temp = ptr->next;
                ptr->next=gcdNode;
                gcdNode->next = temp;
                ptr=temp;
        }
        return head;
    }
};