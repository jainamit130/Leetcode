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
    int longestUnivaluePath(TreeNode* root) {
        solve(root,INT_MAX);
        return max(0,ans-1);
    }

    pair<int,int> solve(TreeNode* root,int val){
        if(!root){
            return {INT_MAX,0};
        }

        auto leftPair=solve(root->left,val);
        auto rightPair=solve(root->right,val);
        int count=1;
        if(leftPair.first==root->val){
            count+=leftPair.second;
        }
        if(rightPair.first==root->val){
            count+=rightPair.second;
        }
        ans=max(ans,count);
        return {root->val,count};
    }
};


//Values can be anything
//Root can be Null
//10000
//Number of Nodes: 0 - 10000
//