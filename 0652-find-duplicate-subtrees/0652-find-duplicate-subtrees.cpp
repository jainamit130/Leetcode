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
    unordered_map<string,pair<TreeNode*,int>> mp;
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        solve(root);
        vector<TreeNode*> ans;
        for(auto [a,b]:mp){
            if(b.second>1){
                ans.push_back(b.first);
            }
        }
        return ans;
    }

    string solve(TreeNode* root){
        if(!root){
            return "N";
        }

        string a=solve(root->left);
        string b=solve(root->right);
        string c=to_string(root->val)+","+a+","+b;
        if(mp.find(c)==mp.end()){
            mp[c]={root,1};
        } else {
            mp[c].second++;
        }
        return c;
    }
};