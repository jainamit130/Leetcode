/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode rev1 = reverse(l1);
        ListNode rev2 = reverse(l2);
        ListNode ptr1 = rev1;
        ListNode ptr2 = rev2;
        ListNode ans = null;
        ListNode ptr = null;
        int carry = 0;
        while(ptr1!=null || ptr2!=null || carry>0) {
            int sum = carry;
            if(ptr1!=null) { sum += ptr1.val; ptr1=ptr1.next; }
            if(ptr2!=null) { sum += ptr2.val; ptr2=ptr2.next; }
            carry = sum/10;
            sum = sum%10;
            if(ans==null) {
                ans = new ListNode(sum);
                ptr = ans;
            } else {
                ptr.next = new ListNode(sum);
                ptr=ptr.next;
            }
        }
        return reverse(ans);
    }

    public ListNode reverse(ListNode l) {
        ListNode p = null;
        ListNode n = l;
        while(n!=null) {
            ListNode t = n.next;
            n.next = p;
            p = n;
            n = t;
        }
        return p;
    }
}

/*


reverse both list

do the addition

and then reverse it back

7   2   4   3
    5   6   4


3   4   2   7
4   6   5

sum = 18 => % 10 to get sum and then /10 to get carry
result =>   7   0   8   7     
carry =>    1   


Reversal

N<- 7 <- 2  <- 4   3


temp => n -> next
n -> next = p
p = n
n = t
t = n -> next
*/ 