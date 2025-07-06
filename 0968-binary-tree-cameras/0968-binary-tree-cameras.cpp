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
        return min(dfs(root,0,cache),1+dfs(root,2,cache));
    }

    int dfs(TreeNode* root,int state,unordered_map<TreeNode*,unordered_map<int,int>>& cache){
        if(!root){
            return 0;
        }

        if(cache[root].find(state)!=cache[root].end()){
            return cache[root][state];
        }

        int ans=1001;
        if(state==2){
            ans=min(ans,dfs(root->left,1,cache)+dfs(root->right,1,cache));
        } else if(state==1){
            ans=min(ans,dfs(root->left,0,cache)+dfs(root->right,0,cache));
            ans=min(ans,1+dfs(root->left,1,cache)+dfs(root->right,1,cache));
        } else if(state==0){
            ans=min(ans,1+dfs(root->left,1,cache)+dfs(root->right,1,cache));
            ans=min(ans,1+dfs(root->left,2,cache)+dfs(root->right,0,cache));
            ans=min(ans,1+dfs(root->left,0,cache)+dfs(root->right,2,cache));
            ans=min(ans,2+dfs(root->left,2,cache)+dfs(root->right,2,cache));
        }
        return cache[root][state]=ans;
    }
};


/*

if 2 => send state 1 to immediate neighbors 
if 1 => either skip (sending 0 state to children) or add camer (increment ans and send 1 to the children)

if 0 => place camera on current node and pass 1 to the children(increment ans by 1)
     => place camera on left node and pass 2 to left and 0 to right(increment ans by 1)
     => place camera on right node and pass 2 to right and 0 to left(increment ans by 1)
     => place camera on both children and pass 2 to both (increment ans by 2)


*/