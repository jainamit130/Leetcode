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
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode*> q;
        root->val = 0;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            int sum = 0;
            unordered_map<TreeNode*,int> currSumMp; 
            while(size){
                TreeNode* node = q.front();
                q.pop();
                size--;
                if(node->left){
                    sum+=node->left->val;
                    currSumMp[node]+=node->left->val;
                    q.push(node->left);
                }
                if(node->right){
                    sum+=node->right->val;
                    currSumMp[node]+=node->right->val;
                    q.push(node->right);
                }
            }

            for(auto [node,itsSum] : currSumMp){
                if(node->left){
                    node->left->val = sum-itsSum;
                }
                if(node->right){
                    node->right->val = sum-itsSum;
                }
            }
        }
        return root;
    }
};