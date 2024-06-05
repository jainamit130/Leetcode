int mod=1e9 + 7;

class Solution {
public:

    void build(int ind,int low,int high,vector<int> &nums,vector<vector<int>> &seg){
        if(low==high){
            // seg[ind][0][0]=0;
            // cout<<"vimal"<<endl;
            seg[ind][0]=0;
            seg[ind][1]=-1e9;
            seg[ind][2]=-1e9;
            seg[ind][3]=nums[low];
            // seg[ind][0][1]=-1e9;
            // seg[ind][1][0]=-1e9;
            // seg[ind][1][1]=nums[low];
            return;
        }
        int mid = low + (high - low)/2;
        build(2*ind + 1,low,mid,nums,seg);
        build(2*ind + 2,mid+1,high,nums,seg);
        seg[ind][0] = max(seg[2*ind + 1][0] + seg[2*ind + 2][0] , max(seg[2*ind + 1][1] + seg[2*ind + 2][0] ,seg[2*ind+1][0] + seg[2*ind+2][2]));
        seg[ind][1] = max(seg[2*ind + 1][0] + seg[2*ind + 2][1] , max(seg[2*ind + 1][1] + seg[2*ind + 2][1] ,seg[2*ind+1][0] + seg[2*ind+2][3]));
        seg[ind][2] = max(seg[2*ind + 1][2] + seg[2*ind + 2][0] , max(seg[2*ind + 1][3] + seg[2*ind + 2][0] ,seg[2*ind+1][2] + seg[2*ind+2][2]));
        seg[ind][3] = max(seg[2*ind + 1][2] + seg[2*ind + 2][1] , max(seg[2*ind + 1][3] + seg[2*ind + 2][1] ,seg[2*ind+1][2] + seg[2*ind+2][3]));
    }

    void update(int ind,int low,int high,vector<int> &nums,vector<vector<int>> &seg,int k,int val){
        if(low>k || high<k){
            return;
        }
        if(low == high && high == k){
           seg[ind][0]=0;
           seg[ind][3]=val;
           return ;
        }
        int mid=low + (high - low)/2;
        update(2*ind+1,low,mid,nums,seg,k,val);
        update(2*ind + 2,mid+1,high,nums,seg,k,val);
         seg[ind][0] = max(seg[2*ind + 1][0] + seg[2*ind + 2][0] , max(seg[2*ind + 1][1] + seg[2*ind + 2][0] ,seg[2*ind+1][0] + seg[2*ind+2][2]));
        seg[ind][1] = max(seg[2*ind + 1][0] + seg[2*ind + 2][1] , max(seg[2*ind + 1][1] + seg[2*ind + 2][1] ,seg[2*ind+1][0] + seg[2*ind+2][3]));
        seg[ind][2] = max(seg[2*ind + 1][2] + seg[2*ind + 2][0] , max(seg[2*ind + 1][3] + seg[2*ind + 2][0] ,seg[2*ind+1][2] + seg[2*ind+2][2]));
        seg[ind][3] = max(seg[2*ind + 1][2] + seg[2*ind + 2][1] , max(seg[2*ind + 1][3] + seg[2*ind + 2][1] ,seg[2*ind+1][2] + seg[2*ind+2][3]));
    }

    int maximumSumSubsequence(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        // vector<vector<vector<int>>> seg(4*n+1,vector<vector<int>> (2,vector<int> (2,-1)));
        vector<vector<int>> seg(4*n+1,vector<int>(5,0));
        build(0,0,n-1,nums,seg);
        int m=queries.size();
        int ans=0;
        for(int i=0;i<m;i++){
            update(0,0,n-1,nums,seg,queries[i][0],queries[i][1]);
            ans = (ans + max(seg[0][0],max(seg[0][1],max(seg[0][2],seg[0][3]))))%mod;
        }
        return ans;


    }
};

// vector<vector<int>> dir={{0,0},{0,1},{1,0},{1,1}};
// int mod=1e9+7;
// class SegmentTree {
//     public:
//         int leftIndex;
//         int rightIndex;
//         SegmentTree* left;
//         SegmentTree* right;
//         vector<vector<int>> val;
//         SegmentTree(int li,int ri){
//             val.resize(2,vector<int>(2,INT_MIN));
//             leftIndex=li;
//             rightIndex=ri;
//             left=NULL;
//             right=NULL;
//         }

//         //construct
//         SegmentTree* construct(vector<int>& nums,int leftIndex,int rightIndex){
//             if(leftIndex==rightIndex){
//                 SegmentTree* leaf = new SegmentTree(leftIndex,leftIndex);
//                 leaf->val[0][0]=0;
//                 leaf->val[0][1]=-1e9;
//                 leaf->val[1][0]=-1e9;
//                 leaf->val[1][1]=nums[leftIndex];
//                 return leaf;
//             } 
//             SegmentTree* root=new SegmentTree(leftIndex,rightIndex);
//             int mid=(leftIndex+rightIndex)/2;
//             root->left=construct(nums,leftIndex,mid);
//             root->right=construct(nums,mid+1,rightIndex);
//             for(auto d:dir){
//                 root->val[d[0]][d[1]]=max(root->left->val[d[0]][0]+root->right->val[0][d[1]],
//                                           max(root->left->val[d[0]][0]+root->right->val[1][d[1]],
//                                           root->left->val[d[0]][1]+root->right->val[0][d[1]]));
//             }
//             return root;
//         }

//         //update
//         void update(int index,int val){
//             if(this->leftIndex==this->rightIndex && this->leftIndex==index){
//                 this->val[0][0]=0;
//                 this->val[0][1]=-1e9;
//                 this->val[1][0]=-1e9;
//                 this->val[1][1]=val;
//                 return;
//             }

//             int mid=(this->leftIndex+this->rightIndex)/2;
//             if(index<=mid){
//                 this->left->update(index,val);
//             } else {
//                 this->right->update(index,val);
//             }
//             for(auto d:dir){
//                 this->val[d[0]][d[1]]=max(this->left->val[d[0]][0]+this->right->val[0][d[1]],
//                                           max(this->left->val[d[0]][0]+this->right->val[1][d[1]],
//                                           this->left->val[d[0]][1]+this->right->val[0][d[1]]));
//             }
//             return;
//         }
// };

// class Solution {
// public:
//     int maximumSumSubsequence(vector<int>& nums, vector<vector<int>>& queries) {
//         SegmentTree* root=new SegmentTree(0,nums.size()-1);
//         root=root->construct(nums,0,nums.size()-1);
//         int result=0;
//         for(auto q:queries){
//             int ans=INT_MIN;
//             root->update(q[0],q[1]);
//             for(auto d:dir){
//                 ans=max(ans,root->val[d[0]][d[1]]);
//             }
//             result=(result+ans)%mod;
//         }
//         return result;
//     }
// };