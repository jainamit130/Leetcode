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
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        unordered_map<int,int> mp;
        vector<int> ans(queries.size());
        for(int i=0;i<queries.size();i++){
            generateHeight(root,mp,queries[i]);
            ans[i]=mp[root->val]-1;
        }
        return ans;
    }

    int generateHeight(TreeNode* root,unordered_map<int,int>& mp,int query){
        if(!root){
            return 0;
        }

        if(root->val==query){
            return 0;
        }

        mp[root->val]=max(1+generateHeight(root->left,mp,query),1+generateHeight(root->right,mp,query));
        return mp[root->val];
    }
};