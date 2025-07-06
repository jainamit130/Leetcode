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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* prevL = NULL;
        ListNode* leftPtr = head;
        ListNode* nextR = NULL;
        ListNode* rightPtr = head;
        while(left-1) {
            prevL = leftPtr;
            leftPtr = leftPtr->next;
            left--;
        }

        while(right-1) {
            rightPtr = rightPtr->next;
            right--;
        }

        nextR = rightPtr->next;
        ListNode* lastPtr = reverseLinkedList(leftPtr,rightPtr);
        if(prevL) prevL->next = rightPtr;
        if(nextR) lastPtr->next = nextR;
        return head;
    }

    ListNode* reverseLinkedList(ListNode* leftPtr,ListNode* rightPtr) {
        if(leftPtr==rightPtr) {
            return leftPtr;
        }

        ListNode* nextPtr = reverseLinkedList(leftPtr->next,rightPtr);
        nextPtr->next = leftPtr;
        return leftPtr;
    }
};


/*

a   b   c   d   e   f
l               r


a   b   c   d   e   f
    l               r


a   b   c   d   e   f
l                   r


a -> b <- c <- d <- e -> f
     l              r
              



a -> e -> d -> c -> b -> f



*/