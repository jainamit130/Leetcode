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
    int ans=0;
    int longestUnivaluePath(TreeNode* root) {
        solve(root);
        return ans;
    }

    pair<int,int> solve(TreeNode* root){
        if(!root){
            return {INT_MAX,0};
        }

        auto leftPair=solve(root->left);
        auto rightPair=solve(root->right);
        int count=0;
        if(leftPair.first==root->val){
            count=max(count,1+leftPair.second);
        }
        if(rightPair.first==root->val){
            count=max(count,1+rightPair.second);
        }

        if(rightPair.first==root->val && leftPair.first==root->val){
            ans=max(ans,2+leftPair.second+rightPair.second);
        }
        ans=max(ans,count);
        return {root->val,count};
    }
};