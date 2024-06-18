class SegmentTree {
    public:
    int leftI;
    int rightI;
    int numPeaks;
    SegmentTree* left;
    SegmentTree* right;

    SegmentTree(int leftIndex,int rightIndex,int val) {
        left=NULL;
        right=NULL;
        leftI=leftIndex;
        rightI=rightIndex;
        numPeaks=val;
    }

    SegmentTree* construct(vector<int> nums,int leftIndex, int rightIndex){
        if(leftIndex==rightIndex){
            return new SegmentTree(leftIndex,rightIndex,(leftIndex>0 && leftIndex<nums.size()-1 && nums[leftIndex-1]<nums[leftIndex] && nums[leftIndex+1]<nums[leftIndex]));
        }
        int mid = (leftIndex + rightIndex) / 2;
        SegmentTree* root = new SegmentTree(leftIndex,rightIndex,0);
        root->left = construct(nums,leftIndex,mid);
        root->right = construct(nums,mid+1,rightIndex);
        root->numPeaks=root->left->numPeaks+root->right->numPeaks;
        return root;
    }

    int update(SegmentTree* root,int index,int val){
        if(index==root->leftI && root->rightI==index){
            root->numPeaks=val;
            return root->numPeaks;
        }

        int mid = (root->leftI+root->rightI)/2;
        if(index<=mid){
            root->left->numPeaks=update(root->left,index,val);
        } else {
            root->right->numPeaks=update(root->right,index,val);
        }
        root->numPeaks=root->left->numPeaks+root->right->numPeaks;
        return root->numPeaks;
    }

    int query(int leftIndex,int rightIndex,SegmentTree* root){
        if(root->rightI==rightIndex && root->leftI==leftIndex)
            return root->numPeaks;

        if(leftIndex>rightIndex)
            return 0;
        // cout<<leftIndex<<" "<<rightIndex<<endl;
        int midIndex=(root->leftI+root->rightI)/2;
        int ans=0;
        if(leftIndex<=midIndex && midIndex<=rightIndex){
            ans+=query(leftIndex,midIndex,root->left)+query(midIndex+1,rightIndex,root->right);
        } else if(midIndex<leftIndex) {
            ans+=query(leftIndex,rightIndex,root->right);
        } else {
            ans+=query(leftIndex,rightIndex,root->left);
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        SegmentTree* root = new SegmentTree(0,0,0);
        root=root->construct(nums,0,nums.size()-1);
        vector<int> ans;
        for(auto q:queries){
            if(q[0]==2){
                updateIfRequired(q[1],q[2],root,nums);
                nums[q[1]]=q[2];
            } else {
                // cout<<"Search"<<endl;
                ans.push_back(root->query(q[1]+1,q[2]-1,root));
            }
        }
        return ans;
    }

void updateIfRequired(int index, int newVal, SegmentTree* root, vector<int>& nums) {
    int oldValue = nums[index];    
    for (int i = -1; i <= 1; i++) {
        int currIndex = index + i;
        if (!(currIndex > 0 && currIndex < nums.size() - 1)) {
            continue;
        }
        
        int oldCondition = (nums[currIndex - 1] < nums[currIndex] && nums[currIndex + 1] < nums[currIndex]);
        
        nums[index] = oldValue;
        int oldPeakCondition = (nums[currIndex - 1] < nums[currIndex] && nums[currIndex + 1] < nums[currIndex]);
        
        nums[index] = newVal;
        int newPeakCondition = (nums[currIndex - 1] < nums[currIndex] && nums[currIndex + 1] < nums[currIndex]);
        
        
        if (oldPeakCondition != newPeakCondition) {
            root->update(root,currIndex, newPeakCondition);
        }
    }
}

};



/*


3   1   4   2   5


3   1   4   4   5





*/