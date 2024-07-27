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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root){
            return NULL;
        }

        if(root->val==key){
            if(!root->left || !root->right){
                if(root->left){
                    return root->left;
                }
                if(root->right){
                    return root->right;
                }
                return NULL;
            } else {
                root->val=getLowestVal(root->right);
                root->right=deleteNode(root->right,root->val);
                return root;
            }
        }
        root->left=deleteNode(root->left,key);
        root->right=deleteNode(root->right,key);
        return root;
    }

    int getLowestVal(TreeNode* root){
        if(!root){
            return INT_MAX;
        }
        
        int ans=INT_MAX;
        ans=min(ans,min(root->val,getLowestVal(root->left)));
        return ans;
    }
};