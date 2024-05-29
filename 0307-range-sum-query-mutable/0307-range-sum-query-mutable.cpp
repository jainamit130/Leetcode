class SegmentTree {
    public:
        int l;
        int r;
        int total;
        SegmentTree* left;
        SegmentTree* right;
        SegmentTree(int leftIndex,int rightIndex,int val){
            l=leftIndex;
            r=rightIndex;
            total=val;
            left=NULL;
            right=NULL;
        }
};

class NumArray {
        SegmentTree* construct(int leftIndex,int rightIndex,vector<int>& nums){
            if(leftIndex==rightIndex){
                return new SegmentTree(leftIndex,rightIndex,nums[leftIndex]);
            }

            int midIndex=(leftIndex+rightIndex)/2;
            SegmentTree* root=new SegmentTree(leftIndex,rightIndex,0);
            SegmentTree* leftTree=construct(leftIndex,midIndex,nums);
            SegmentTree* rightTree=construct(midIndex+1,rightIndex,nums);
            root->left=leftTree;
            root->right=rightTree;
            root->total=leftTree->total+rightTree->total;
            return root;
        }


        void updateTree(int index,int val,SegmentTree* root){
            if(root->l==root->r){
                root->total=val;
                return;
            }

            int midIndex=(root->l+root->r)/2;
            if(midIndex>=index){
                updateTree(index,val,root->left);
            } else {
                updateTree(index,val,root->right);
            }
            root->total=root->left->total+root->right->total;
            return;
        }

        int calculateTree(int leftIndex,int rightIndex,SegmentTree* root){
            if(root->r==root->l)
                return root->total;

            if(leftIndex>rightIndex)
                return 0;

            int midIndex=(root->l+root->r)/2;
            int ans=0;
            if(leftIndex<=midIndex && midIndex<=rightIndex){
                ans+=calculateTree(leftIndex,midIndex,root->left)+calculateTree(midIndex+1,rightIndex,root->right);
            } else if(midIndex<leftIndex) {
                ans+=calculateTree(leftIndex,rightIndex,root->right);
            } else {
                ans+=calculateTree(leftIndex,rightIndex,root->left);
            }
            return ans;
        }
public:
    SegmentTree* root; 
    NumArray(vector<int>& nums) {
        root=construct(0,nums.size()-1,nums);
    }
    
    void update(int index, int val) {
        updateTree(index,val,root);
    }
    
    int sumRange(int left, int right) {
        return calculateTree(left,right,root);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */