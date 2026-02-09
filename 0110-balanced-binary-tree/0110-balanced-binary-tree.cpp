/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool c=true;
    bool isBalanced(TreeNode* root) {
       maxDepth(root);
       return c; 
    }

    int maxDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        int maxL=maxDepth(root->left);
        int maxR=maxDepth(root->right);
        if(abs(maxL-maxR)>1)
            c=false;
        return max(maxL+1,maxR+1);
    }
};