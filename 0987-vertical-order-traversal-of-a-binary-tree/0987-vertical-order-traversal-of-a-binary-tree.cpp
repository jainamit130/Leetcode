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
    map<int,vector<vector<int>>> mp;
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        traverse(root,0,0);
        vector<vector<int>> ans;
        for(auto [a,b]:mp){
            sort(b.begin(),b.end(),[](auto lhs,auto rhs){
                if(lhs[0]==rhs[0]){
                    return lhs[1]<rhs[1];
                }
                return lhs[0]<rhs[0];
            });
            vector<int> temp;
            for(auto c:b){
                temp.push_back(c[1]);
            }
            ans.push_back(temp);
        }
        return ans;
    }

    void traverse(TreeNode* root,int row,int col){
        if(!root){
            return;
        }

        //process
        mp[col].push_back({row,root->val});
        traverse(root->left,row+1,col-1);
        traverse(root->right,row+1,col+1);
        return;
    }
};