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
    bool isCousins(TreeNode* root, int x, int y) {
        if(root->val==x || root->val==y){
            return false;
        }
        queue<TreeNode*> q;
        q.push(root);
        int depthx=-1;
        int depthy=-1;
        int px=-1;
        int py=-1;
        int level=0;
        while(!q.empty()){
            int size=q.size();
            while(size){
                TreeNode* node=q.front();
                cout<<node->val<<endl;
                q.pop();
                size--;
                if(node->left){
                    if(node->left->val==x){
                        depthx=level+1;
                        px=node->val;
                    }
                    if(node->left->val==y){
                        depthy=level+1;
                        py=node->val;
                    }
                    q.push(node->left);
                }
                if(node->right){
                    if(node->right->val==x){
                        depthx=level+1;
                        px=node->val;
                    }
                    if(node->right->val==y){
                        depthy=level+1;
                        py=node->val;
                    }
                    q.push(node->right);
                }
                if(depthx!=-1 && depthy!=-1){
                    return depthx==depthy && px!=py;
                }
            }
            level++;
        }
        return false;
    }
};