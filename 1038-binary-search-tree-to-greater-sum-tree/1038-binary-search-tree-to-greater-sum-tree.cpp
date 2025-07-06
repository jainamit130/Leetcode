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
    TreeNode* bstToGst(TreeNode* root) {
        int sum=0;
        solve(root,sum);   
        return root;
    }

    void solve(TreeNode* root,int& sum){
        if(!root){
            return;
        }

        solve(root->right,sum);
        sum+=root->val;
        root->val=sum;
        solve(root->left,sum);
        return;
    }
};


// class Solution {
// public:
//     TreeNode* bstToGst(TreeNode* root) {
//         int sum=findSum(root);
//         solve(root,sum);   
//         return root;
//     }

//     int findSum(TreeNode* root){
//         if(!root){
//             return 0;
//         }

//         int sum=0;
//         sum+=root->val + findSum(root->left) + findSum(root->right);
//         return sum;
//     }

//     void solve(TreeNode* root,int& sum){
//         if(!root){
//             return;
//         }

//         solve(root->left,sum);
//         int temp=root->val;
//         root->val=sum;
//         sum-=temp;
//         solve(root->right,sum);
//         return;
//     }
// };