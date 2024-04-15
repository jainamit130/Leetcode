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
    int sumNumbers(TreeNode* root,int sum=0) {
        if(!root)
            return 0;

        if(!root->left && !root->right){
            return sum*10+root->val;
        }
        return sumNumbers(root->left,sum*10+root->val)+sumNumbers(root->right,sum*10+root->val);
    }
};