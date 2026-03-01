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
    int sum = 0;
    int sumRootToLeaf(TreeNode* root) {
        populateSum(root,0);
        return sum/2;
    }

    void populateSum(TreeNode* root,int val) {
        if(!root) {sum += val; return;}
        populateSum(root->left,val*2+root->val);
        populateSum(root->right,val*2+root->val);
        return;
    }    
};