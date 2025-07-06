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
    vector<vector<string>> ans;
    int height;
    vector<vector<string>> printTree(TreeNode* root) {
        height=findHeight(root)-1;
        int col=(1<<(height+1))-1;
        ans.resize(height+1,vector<string>(col,""));
        dfs(root,0,(col-1)/2);
        return ans;   
    }

    void dfs(TreeNode* root,int row,int col){
        if(!root){
            return;
        }
        if(row>height){
            return;
        }
        ans[row][col]=to_string(root->val);
        dfs(root->left,row+1,col-(pow(2,height-row-1)));
        dfs(root->right,row+1,col+(pow(2,height-row-1)));
        return;
    }

    int findHeight(TreeNode* root){
        if(!root){
            return 0;
        }

        return max(findHeight(root->left)+1,findHeight(root->right)+1);
    }
};