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
    vector<int> levels;
    vector<int> height;
    vector<pair<int,int>> firstAndSecondMax;
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        levels.resize(1e5+1);
        height.resize(1e5+1);
        firstAndSecondMax.resize(1e5+1,{-1,-1});
        solve(root,0);
        vector<int> ans;

        for(int i=0;i<queries.size();i++){
            int currLevel = levels[queries[i]];
            int currHeight = height[queries[i]];
            int firstMax = firstAndSecondMax[currLevel].first;
            int secondMax = firstAndSecondMax[currLevel].second;
            if(currHeight==firstMax){
                ans.push_back(secondMax+currLevel);
            } else {
                ans.push_back(firstMax+currLevel);
            }
        }
        return ans;
    }

    int solve(TreeNode* root,int level){
        if(!root){
            return 0;
        }

        levels[root->val]=level;
        int leftHeight = solve(root->left,level+1);
        int rightHeight = solve(root->right,level+1);
        int currHeight = max(leftHeight, rightHeight);
        height[root->val] = currHeight;

        auto& maxPair = firstAndSecondMax[level];
        int firstMax = maxPair.first;
        int secondMax = maxPair.second;

        if (currHeight > firstMax) {
            maxPair.second = firstMax;
            maxPair.first = currHeight;
        } else if (currHeight > secondMax) {
            maxPair.second = currHeight;
        }
        firstAndSecondMax[level]=maxPair;
        return height[root->val]+1;
    }
};