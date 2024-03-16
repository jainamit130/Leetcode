/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
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