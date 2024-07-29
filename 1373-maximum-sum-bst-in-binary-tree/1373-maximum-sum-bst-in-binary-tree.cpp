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
    int maxSumBST(TreeNode* root) {
        solve(root);
        return ans;
    }

    pair<bool,vector<int>> solve(TreeNode* root){
        if(!root){
            return {true,{0,INT_MAX,INT_MIN}};
        }

        auto a=solve(root->left);
        auto b=solve(root->right);
        if(a.first && b.first && (a.second[1]==INT_MAX || a.second[2]<root->val) && (b.second[2]==INT_MIN || b.second[1]>root->val)){
            int sum=a.second[0]+b.second[0]+root->val;
            ans=max(ans,sum);
            return {true,{sum,min(a.second[1],min(b.second[1],root->val)),max(b.second[2],max(root->val,a.second[2]))}};
        }
        return {false,{0,INT_MAX,INT_MIN}};
    }
};