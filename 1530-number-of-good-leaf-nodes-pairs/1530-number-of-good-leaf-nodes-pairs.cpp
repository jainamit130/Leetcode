/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;
    int countPairs(TreeNode* root, int distance) {
        vector<vector<int>> depths;
        traverse(root, distance, depths);
        return ans;
    }

    bool traverse(TreeNode* root, int distance, vector<vector<int>>& depths) {
        if (!root) {
            return false;
        }

        for (int i = 0; i < depths.size(); i++) {
            depths[i][0]++;
            depths[i][1]++;
        }

        bool a=traverse(root->left, distance, depths);

        if (!root->left && !root->right) {
            for (int i = 0; i < depths.size(); i++) {
                if (depths[i][0] <= distance) {
                    ans++;
                }
            }
        }


        if(a){
        for (int i = 0; i < depths.size(); i++) {
            if (depths[i][1] > 0) {
                depths[i][0]--;
                depths[i][1]--;
            } else {
                depths[i][0]++;
            }
        }
        }


       bool b=traverse(root->right, distance, depths);

        if(b){
        for (int i = 0; i < depths.size(); i++) {
            if (depths[i][1] > 0) {
                depths[i][0]--;
                depths[i][1]--;
            } else {
                depths[i][0]++;
            }
        }
        }
        
        if (!root->left && !root->right) {
            depths.push_back({0, 0});
        }


        return true;
    }
};