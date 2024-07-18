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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int flag=0;
        while(!q.empty()){
            int size=q.size();
            while(size){
                TreeNode* parent=q.front();
                q.pop();
                size--;
                if(flag){
                    if(parent->left!=NULL || parent->right!=NULL){
                        return false;
                    }
                    continue;
                }
                if(parent->left){
                    q.push(parent->left);
                    if(parent->right){
                        q.push(parent->right);
                    } else {
                        flag=1;
                    }
                } else {
                    if(parent->right){
                        return false;
                    }
                    flag=1;
                }
            }
        }
        return true;
    }
};