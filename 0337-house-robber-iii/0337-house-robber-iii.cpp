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
    int rob(TreeNode* root) {
        unordered_map<TreeNode*,unordered_map<bool,int>> cache;
        return max(solve(root,0,cache),solve(root,1,cache));
    }

    int solve(TreeNode* root,bool chosen,unordered_map<TreeNode*,unordered_map<bool,int>>& cache){
        if(!root){
            return 0;
        }

        if(cache.find(root)!=cache.end() && cache[root].find(chosen)!=cache[root].end()){
            return cache[root][chosen];
        }

        int ans=0;
        if(chosen){
            ans=max(ans,root->val+solve(root->left,false,cache)+solve(root->right,false,cache));
            ans=max(ans,solve(root->left,true,cache)+solve(root->right,true,cache));
        } else {
            ans=max(ans,solve(root->left,true,cache)+solve(root->right,true,cache));
        }
        
        return cache[root][chosen]=ans;
    }
};