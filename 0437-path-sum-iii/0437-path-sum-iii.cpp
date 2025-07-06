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
    int ans = 0;
    int pathSum(TreeNode* root, int targetSum) {
        solve(root,targetSum);
        return ans/2;
    }

    void solve(TreeNode* root,int targetSum) {
        if(!root) return;
        calculatePathSum(root,targetSum,INT_MAX); 
        solve(root->left,targetSum);
        solve(root->right,targetSum);
        return;
    }

    void calculatePathSum(TreeNode* root,int targetSum,long long currSum) {
        if(!root) { ans+=targetSum==currSum; return;}
        ans += currSum==targetSum;
        if(currSum==INT_MAX) currSum=0;
        calculatePathSum(root->left,targetSum,currSum*1LL+root->val);
        calculatePathSum(root->right,targetSum,currSum*1LL+root->val);
        return;
    }
};