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
        vector<int> nodes(1001);
        for(int i=0;i<to_delete.size();i++){
            nodes[to_delete[i]]=1;
        }
        vector<TreeNode*> ans;
        dfs(root,nodes,ans);
        if(!nodes[root->val]){
            ans.push_back(root);
        }
        return ans;
    }

    TreeNode* dfs(TreeNode* root,vector<int> nodes,vector<TreeNode*>& ans){
        if(!root){
            return NULL;
        }

        dfs(root->left,nodes,ans);
        dfs(root->right,nodes,ans);
        if(nodes[root->val]){
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