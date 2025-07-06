/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        return solve(head).first;
    }

    pair<Node*,Node*> solve(Node* head){
        if(!head){
            return {NULL,NULL};
        }

        auto flatChild=solve(head->child); // 3 3
        auto flatNext=solve(head->next); // N N
        if(flatChild.first){
            head->next=flatChild.first;
            flatChild.second->next=flatNext.first;
            flatChild.first->prev=head;
        } else {
            head->next=flatNext.first;
        }
        if(flatNext.first){
            if(flatChild.second){
                flatNext.first->prev=flatChild.second;
            } else {
                flatNext.first->prev=head;
            }
        }
        Node* tail=head;
        while(tail->next){
            tail=tail->next;
        }
        head->child=NULL;
        return {head,tail};
    }
};