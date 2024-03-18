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
    int maxi=0;
    int longestZigZag(TreeNode* root) {
        traverseZigZag(root,true,0);
        traverseZigZag(root,false,0);
        return maxi;
    }

    void traverseZigZag(TreeNode* root,bool isLeft,int depth){
        if(!root)
            return;

        maxi=max(maxi,depth);

        if(!isLeft) {   
            traverseZigZag(root->left,!isLeft,depth+1);
            traverseZigZag(root->right,isLeft,1);
        }
        else {
            traverseZigZag(root->right,!isLeft,depth+1);
            traverseZigZag(root->left,!isLeft,1);
        }
        return;
    }
};