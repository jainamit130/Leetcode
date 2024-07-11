class SegmentTree{
    public:
    int leftIndex;
    int rightIndex;
    SegmentTree* left;
    SegmentTree* right;
    int maxNum;
        SegmentTree(int leftI,int rightI,int val){
            leftIndex=leftI;
            rightIndex=rightI;
            maxNum=val;
            left=NULL;
            right=NULL;
        } 

        void updateTree(int index,int val,SegmentTree* root){
            if(root->leftIndex==root->rightIndex){
                root->maxNum=val;
                return;
            }

            int midIndex=(root->leftIndex+root->rightIndex)/2;
            if(midIndex>=index){
                updateTree(index,val,root->left);
            } else {
                updateTree(index,val,root->right);
            }
            root->maxNum=max(root->left->maxNum,root->right->maxNum);
            return;
        }

        
        int query(int leftI,int rightI,SegmentTree* root){
            if(root->rightIndex==rightI && root->leftIndex==leftI)
                return root->maxNum;

            if(leftI>rightI){
                return -1;
            }

            int midIndex=(root->leftIndex+root->rightIndex)/2;
            int ans=0;
            if(leftI<=midIndex && midIndex<=rightI){
                ans=max(ans,max(query(leftI,midIndex,root->left),query(midIndex+1,rightI,root->right)));
            } else if(midIndex<leftI) {
                ans=max(ans,query(leftI,rightI,root->right));
            } else {
                ans=max(ans,query(leftI,rightI,root->left));
            }
            return ans;
        }
};

SegmentTree* construct(int leftI,int rightI){
    if(leftI==rightI){
        return new SegmentTree(leftI,rightI,-1);
    }

    int midIndex=(leftI+rightI)/2;
    SegmentTree* root=new SegmentTree(leftI,rightI,0);
    SegmentTree* leftTree=construct(leftI,midIndex);
    SegmentTree* rightTree=construct(midIndex+1,rightI);
    root->left=leftTree;
    root->right=rightTree;
    root->maxNum=max(leftTree->maxNum,rightTree->maxNum);
    return root;
}

class Solution {
public:
    int lengthOfLIS(vector<int>& nums, int k) {
        int maxN=-1;
        for(auto n:nums){
            maxN=max(maxN,n);
        }
        stack<int> st;
        SegmentTree* root;
        root=construct(0,maxN+k);
        int ans=1;
        for(int i=nums.size()-1;i>=0;i--){
            int n=nums[i];
            while(!st.empty() && (st.top()<=n || st.top()>n+k)){
                st.pop();
            }
            st.push(n);
            int l=root->query(n+1,n+k,root)+1;
            ans=max(ans,l);
            root->updateTree(n,l,root);
        }   
        return ans; 
    }
};