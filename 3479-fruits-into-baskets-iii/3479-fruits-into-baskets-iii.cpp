class SegmentTree {
    public:
        int leftIndex;
        int rightIndex;
        int value;
        SegmentTree* leftTree;
        SegmentTree* rightTree;
        SegmentTree(int lIndex,int rIndex,int val=0) {
            leftTree = NULL;
            rightTree = NULL;
            leftIndex = lIndex;
            rightIndex = rIndex;
            value = val;
        }

        SegmentTree* addNode(int leftIndex,int rightIndex,int value) {
            if(leftIndex == rightIndex) {
                return new SegmentTree(leftIndex,rightIndex,value);
            }

            int midIndex = (leftIndex+rightIndex)/2;
            SegmentTree* newTree = new SegmentTree(leftIndex,rightIndex);
            newTree->leftTree = addNode(leftIndex,midIndex,value);
            newTree->rightTree = addNode(midIndex+1,rightIndex,value);
            newTree->value = max(newTree->leftTree->value,newTree->rightTree->value);
            return newTree;
        }

        bool update(int fruit) {   
            if(this->value<fruit) {
                return false;
            }

            if(this->leftIndex==this->rightIndex) {
                this->value = 0;
                return true;
            }

            if(this->leftTree->update(fruit)) {
                this->value = max(this->leftTree->value,this->rightTree->value);
                return true;
            } else (this->rightTree->update(fruit)) {
                this->value = max(this->leftTree->value,this->rightTree->value);
                return true;
            }
            return false;
        } 
};

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        SegmentTree* tree = new SegmentTree(0,n);
        for(int i=0;i<n;i++) {
            tree = tree->addNode(0,n,baskets[i]);
        }
        int ans = 0;
        for(int i=0;i<n;i++) {
            if(!tree->update(fruits[i])) {
                ans++;
            }
        }
        return ans;
    }
};

/*
3   4   9   2   10  4   6   7

0   1   2   3   4   5   6   7
2   8   1   3   6   1   7   11


0-1 => 1,2
2-2 => 2
3-3 => 3
4-6 => 6
7-8 => 8


*/