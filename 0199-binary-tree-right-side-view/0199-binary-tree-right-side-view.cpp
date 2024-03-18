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
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL) return {};
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* ptr=root;
        vector<int> ans;
        while(!q.empty()){
            int size=q.size();
            while(size){
               TreeNode* temp=q.front();
               q.pop();
               size--;
               if(size==0)
                    ans.push_back(temp->val);
               if(temp->left)
                    q.push(temp->left); 
               if(temp->right)
                    q.push(temp->right); 
            }
        }
        return ans;
    }
};