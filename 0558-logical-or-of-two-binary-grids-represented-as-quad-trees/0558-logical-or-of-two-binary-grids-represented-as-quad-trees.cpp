/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* intersect(Node* quadTree1, Node* quadTree2) {
        if(!quadTree1){
            return quadTree2;
        }

        if(!quadTree2){
            return quadTree1;
        }

        if((quadTree1->isLeaf && quadTree1->val==1) || (quadTree2->isLeaf && quadTree2->val==1)){
            return new Node(1,true);
        }

        if(quadTree1->isLeaf && quadTree2->isLeaf){
           return new Node(quadTree1->val || quadTree2->val,true);
        }

        Node* topL=intersect(quadTree1->topLeft,quadTree2->topLeft);
        Node* topR=intersect(quadTree1->topRight,quadTree2->topRight);
        Node* bottomL=intersect(quadTree1->bottomLeft,quadTree2->bottomLeft);
        Node* bottomR=intersect(quadTree1->bottomRight,quadTree2->bottomRight);
        if(topL->isLeaf && topR->isLeaf && bottomL->isLeaf && bottomR->isLeaf && 
            topL->val==topR->val && topR->val==bottomL->val && bottomL->val==bottomR->val){
            return new Node(topL->val,true);
        }
        return new Node(0,false,topL,topR,bottomL,bottomR);
    }
};

/*

if(q1){
    return q2;
}

if(q2){
    return q1;
}

if((q1->isLeaf && q1->val==1) || (q2->isLeaf && q2->val==1)){
    return new Node(1,true);
}

if(q1->isLeaf && q2->isLeaf){
    return new Node(q1->val || q2->val,true);
}


intersect()

*/