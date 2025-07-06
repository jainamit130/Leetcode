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
            value = val;
            leftIndex = lIndex;
            rightIndex = rIndex;
        }

        void build(int leftIndex,int rightIndex,vector<int>& arr) {
            if(leftIndex == rightIndex) {
                value = arr[leftIndex];
                return;
            }

            int midIndex = (leftIndex+rightIndex)/2;
            SegmentTree* left = new SegmentTree(leftIndex,midIndex);
            SegmentTree* right = new SegmentTree(midIndex+1,rightIndex);
            this->leftTree = left;
            this->rightTree = right;
            left->build(leftIndex,midIndex,arr);
            right->build(midIndex+1,rightIndex,arr);
            value = max(left->value,right->value);
            return;
        }

        // prefer left when both valid, if only right valid then take right otherwise return false
        bool update(int fruit) {
            if(this->value<fruit) return false;

            if(this->leftIndex==this->rightIndex) {
                this->value = 0;
                return true;
            }

            if(this->leftTree->update(fruit) || this->rightTree->update(fruit)) {
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
        SegmentTree* tree= new SegmentTree(0,n-1);
        tree->build(0,n-1,baskets);
        int ans = 0;
        for(auto fruit:fruits) {
            if(!tree->update(fruit)) {
                ans++;
            }
        }
        return ans;
    }
};


/*
ans = 3

3   4   9   2   10  4   6   7
            i

0   1   2   3   4   5   6   7
2   8   1   3   6   1   7   11


for a value at ith index => max value of baskets in the range 0-7 
                         => max value of baskets in the range 0-3 ,  max value of baskets in the range 4-7

Segment Tree => look up of log N => lookup = max value between 2 range


*/
