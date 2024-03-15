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
    int count=0;
    int goodNodes(TreeNode* root) {
        countGoodNodes(root,INT_MIN);
        return count;
    }

    void countGoodNodes(TreeNode* root,int ans){
        if(!root)
            return;

        if(ans<=root->val)
            count++;

        if(ans<=root->val)
            countGoodNodes(root->left,root->val);
        else 
            countGoodNodes(root->left,ans);
        if(ans<=root->val)
            countGoodNodes(root->right,root->val);
        else 
            countGoodNodes(root->right,ans);
        return;
    }
};