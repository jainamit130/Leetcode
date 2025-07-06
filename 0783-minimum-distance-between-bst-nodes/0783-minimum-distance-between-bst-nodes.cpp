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
    int ans=INT_MAX;
    int minDiffInBST(TreeNode* root) {
        solve(root);
        return ans;
    }

    pair<int,int> solve(TreeNode* root){
        if(!root){
            return {INT_MIN,INT_MAX};
        }
        
        if(root->left){
            ans=min(abs(root->val-root->left->val),ans);
        }
        if(root->right){
            ans=min(abs(root->val-root->right->val),ans);
        }

        auto l=solve(root->left);
        auto r=solve(root->right);
        if(l.first!=INT_MIN)
        ans=min(ans,abs(l.first-root->val));
        if(r.second!=INT_MAX)
        ans=min(ans,abs(root->val-r.second));
        return {max(root->val,max(r.first,l.first)),min(root->val,min(r.second,l.second))};
    }
};