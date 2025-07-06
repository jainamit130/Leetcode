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
    int ans = INT_MIN;
    int maxPathSum(TreeNode* root) {
        ans=max(ans,solve(root));
        return ans;
    }

    int solve(TreeNode* root){
        if(!root){
            return -2000;
        }

        int leftSum = solve(root->left);
        int rightSum = solve(root->right);
        ans=max(leftSum+root->val+rightSum,max(ans,max(leftSum,max(root->val,rightSum))));
        return max(leftSum+root->val,max(rightSum+root->val,root->val));
        
    }
};