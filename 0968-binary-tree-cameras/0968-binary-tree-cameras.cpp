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
    int minCameraCover(TreeNode* root) {
        unordered_map<TreeNode*,unordered_map<int,int>> cache;
        return max(1,min(dfs(root,0,cache),1+dfs(root,2,cache)));
    }

    int dfs(TreeNode* root,int cam,unordered_map<TreeNode*,unordered_map<int,int>>& cache){
        if(!root){
            return 0;   
        }

        if(cache[root].find(cam)!=cache[root].end()){
            return cache[root][cam];
        }

        int ans=1001;
        if(cam==2){
            ans=min(ans,dfs(root->left,1,cache)+dfs(root->right,1,cache));
        } else if(cam==1) {
            ans=min(ans,dfs(root->left,0,cache)+dfs(root->right,0,cache));   
            ans=min(ans,1+dfs(root->left,1,cache)+dfs(root->right,1,cache));
        } else if(cam==0){
            ans=min(ans,1+dfs(root->left,1,cache)+dfs(root->right,1,cache));
            ans=min(ans,1+dfs(root->left,2,cache)+dfs(root->right,0,cache));
            ans=min(ans,1+dfs(root->left,0,cache)+dfs(root->right,2,cache));
            ans=min(ans,2+dfs(root->left,2,cache)+dfs(root->right,2,cache));
        }
        cache[root][cam]=ans;
        return ans;
    }
};