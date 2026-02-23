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
    int nope;
    long ans = LONG_MAX;
    int findSecondMinimumValue(TreeNode* root) {
        nope = root->val;
        process(root);
        return ans==LONG_MAX?-1:ans;
    }

    void process(TreeNode* root) {
        if(!root) return;
        process(root->left);
        if(nope!=root->val) ans = min((long)root->val,ans);
        process(root->right);
    }
};