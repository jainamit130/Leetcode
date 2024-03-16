//Brute Force
// class Solution {
// public:
//     int count=0;
//     int pathSum(TreeNode* root, int targetSum) {
//         dfsSolve(root,targetSum);
//         return count/2;
//     }

//     void dfsSolve(TreeNode* root,int targetSum){
//         if(!root)
//             return;

//         solve(root->left,targetSum-root->val);
//         solve(root->right,targetSum-root->val);
//         dfsSolve(root->left,targetSum);
//         dfsSolve(root->right,targetSum);
//         return;
//     }

//     void solve(TreeNode* root,long long targetSum){
//         if(targetSum==0)
//             count++;

//         if(!root)
//             return;

//         solve(root->left,targetSum-root->val);
//         solve(root->right,targetSum-root->val);
//         return;
//     }
// };

class Solution {
public:
    int solve(TreeNode* root, int k, long long sum, unordered_map<long long, int>& mpp){
        if(root == NULL)
            return 0;
            
        sum+=root->val;
        
        int count = mpp[sum - k];
        mpp[sum]++;
        
        int left=solve(root->left, k, sum, mpp);
        int right=solve(root->right, k, sum, mpp);
        
        mpp[sum]--;
        sum-=root->val;
        return count+left+right;
    }
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> mpp;
        mpp[0]=1;
        return solve(root, targetSum, 0, mpp);
    }
};