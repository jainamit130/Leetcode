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
    int moves;
    int dist(TreeNode* root){
        if(!root) return 0;
        int coins = dist(root->left);
        coins += dist(root->right);
        coins += root->val;
        moves += abs(coins-1);
        return coins-1;
    }
    int distributeCoins(TreeNode* root) {
        moves = 0;
        int coins = dist(root);
        return moves;
    }
};