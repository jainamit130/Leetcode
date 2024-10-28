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
    unordered_map<int,int> l,r,height;
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        generateHeight(root);
        preCompute(root->left,r[root->val],1);
        preCompute(root->right,l[root->val],1);
        vector<int> ans(queries.size());
        for(int i=0;i<queries.size();i++){
            ans[i]=height[queries[i]];
        }
        return ans;
    }

    void preCompute(TreeNode* root,int maxPossible,int depth){
        if(!root){
            return;
        }

        height[root->val]=maxPossible;
        preCompute(root->left,max(maxPossible,r[root->val]+depth),depth+1);
        preCompute(root->right,max(maxPossible,l[root->val]+depth),depth+1);
        return;
    }

    int generateHeight(TreeNode* root){
        if(!root){
            return 0;
        }

        l[root->val]=generateHeight(root->left);
        r[root->val]=generateHeight(root->right);

        return max(l[root->val],r[root->val])+1;
    }
};