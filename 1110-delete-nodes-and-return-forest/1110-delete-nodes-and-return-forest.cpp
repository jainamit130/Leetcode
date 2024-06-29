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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> nodes;
        for(int i=0;i<to_delete.size();i++){
            nodes.insert(to_delete[i]);
        }
        vector<TreeNode*> ans;
        dfs(root,nodes,ans);
        if(nodes.find(root->val)==nodes.end()){
            ans.push_back(root);
        }
        return ans;
    }

    TreeNode* dfs(TreeNode* root,unordered_set<int> nodes,vector<TreeNode*>& ans){
        if(!root){
            return NULL;
        }

        root->left=dfs(root->left,nodes,ans);
        root->right=dfs(root->right,nodes,ans);
        if(nodes.find(root->val)!=nodes.end()){
            if(root->left){
                ans.push_back(root->left);
            }
            if(root->right){
                ans.push_back(root->right);
            }
            return NULL;
        }
        return root;
    }

};