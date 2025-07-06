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
    int sumOfLeftLeaves(TreeNode* root) {
        return findSumofLeftLeaves(root,false);
    }

    int findSumofLeftLeaves(TreeNode* root,bool parentLeft){
        if(root==NULL)
            return 0;

        if(root->left==NULL && root->right==NULL && parentLeft){
            return root->val;
        } 
        int sum=0;
        sum+=findSumofLeftLeaves(root->left,true);
        sum+=findSumofLeftLeaves(root->right,false);
        return sum;
    }
};