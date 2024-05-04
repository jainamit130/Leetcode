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
    int ans=INT_MIN;
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
    }

    int dfs(TreeNode* root){
        if(!root){
            return 0;
        }

        int leftMax=dfs(root->left);
        int rightMax=dfs(root->right);
        leftMax=max(0,leftMax);
        rightMax=max(0,rightMax);

        ans=max(ans,root->val+leftMax+rightMax);
        return root->val+max(rightMax,leftMax);
    }
};


/*





*/