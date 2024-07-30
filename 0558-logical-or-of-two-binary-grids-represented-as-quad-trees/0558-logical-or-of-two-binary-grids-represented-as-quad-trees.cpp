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
        if(quadTree1==NULL)
            return quadTree2;

        if(quadTree2==NULL)
            return quadTree1;

        if((quadTree1->isLeaf && quadTree1->val==1) || (quadTree2->isLeaf && quadTree2->val==1)){
            return new Node(1,true);
        }

        if(quadTree1->isLeaf && quadTree2->isLeaf){
            return new Node(quadTree1->val || quadTree2->val,true);
        }

        Node* topLeft = intersect(quadTree1->topLeft, quadTree2->topLeft);
        Node* topRight = intersect(quadTree1->topRight, quadTree2->topRight);
        Node* bottomLeft = intersect(quadTree1->bottomLeft, quadTree2->bottomLeft);
        Node* bottomRight = intersect(quadTree1->bottomRight, quadTree2->bottomRight);

        if (topLeft->isLeaf && topRight->isLeaf && bottomLeft->isLeaf && bottomRight->isLeaf && 
            topLeft->val == topRight->val && topRight->val == bottomLeft->val && bottomLeft->val == bottomRight->val) {
            return new Node(topLeft->val, true);
        } else {
            return new Node(false, false, topLeft, topRight, bottomLeft, bottomRight);
        }
    }
};