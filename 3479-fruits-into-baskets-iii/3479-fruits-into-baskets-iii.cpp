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

        void addNode(int leftIndex,int rightIndex,vector<int>& arr) {
            if(leftIndex == rightIndex) {
                value = arr[leftIndex];
                return;
            }

            int midIndex = (leftIndex+rightIndex)/2;
            SegmentTree* left = new SegmentTree(leftIndex,midIndex);
            SegmentTree* right = new SegmentTree(midIndex+1,rightIndex);
            this->leftTree = left;
            this->rightTree = right;
            left->addNode(leftIndex,midIndex,arr);
            right->addNode(midIndex+1,rightIndex,arr);
            value = max(left->value,right->value);
            return;
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
            } else if(this->rightTree->update(fruit)) {
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
        SegmentTree* tree = new SegmentTree(0,n-1);
        tree->addNode(0,n-1,baskets);
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