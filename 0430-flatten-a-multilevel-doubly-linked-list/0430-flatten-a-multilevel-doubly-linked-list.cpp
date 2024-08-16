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

        Node* tail=head;
        while(tail->next){
            tail=tail->next;
        }
        auto flatChild=solve(head->child);
        auto flatNext=solve(head->next);
        if(flatChild.first){
            head->next=flatChild.first;
            flatChild.second->next=flatNext.first;
            flatChild.first->prev=head;
        } else {
            head->next=flatNext.first;
        }
        if(flatNext.first){
            if(flatChild.first){
                flatNext.first->prev=flatChild.second;
            } else {
                flatNext.first->prev=head;
            }
        }
        head->child=NULL;
        return {head,tail};
    }
};