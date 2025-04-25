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
    int ans = 0;
    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return ans;
    }

    pair<int,int> solve(TreeNode* root) {
        if(!root) return {0,0};

        auto [count1,sum1] = solve(root->right);
        auto [count2,sum2] = solve(root->left);
        if(root->val==(sum1+sum2+root->val)/(1+count1+count2)) {
            ans++;
        }
        return {count1+count2+1,sum1+sum2+root->val};
    }
};