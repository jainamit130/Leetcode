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
    int sumNumbers(TreeNode* root) {
        dfs(root,0);
        return ans;
    }

    void dfs(TreeNode* root,int curr){
        if(!root)
            return;

        if(!root->left && !root->right){
            ans+=curr*10+root->val;
            return;
        }
        dfs(root->left,curr*10+root->val);
        dfs(root->right,curr*10+root->val);
        return;
    }
};