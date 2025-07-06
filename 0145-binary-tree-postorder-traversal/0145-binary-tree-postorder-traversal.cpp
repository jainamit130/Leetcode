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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s;
        s.push(root);
        stack<bool> visited;
        visited.push(false);

        while(!s.empty()){
            TreeNode* curr=s.top(); s.pop();
            bool visit=visited.top();visited.pop();
            if(curr){ 
                if(visit)
                    ans.push_back(curr->val);
                else {
                    s.push(curr);
                    visited.push(true);
                    s.push(curr->right);
                    visited.push(false);
                    s.push(curr->left);
                    visited.push(false);
                }
            }
        }
        return ans;
    }
};