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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        while(root) {
            if(root->left) {
                TreeNode* predecessor = root->left;
                while(predecessor->right && predecessor->right!=root) {
                    predecessor = predecessor->right;
                }
                if(!predecessor->right) {
                    predecessor->right = root;
                    root=root->left;
                } else {
                    predecessor->right = NULL;
                    ans.push_back(root->val);
                    root = root->right;
                }
            } else {
                ans.push_back(root->val);
                root=root->right;
            }
        }
        return ans;
    }
};



/*

check if left exists
 => if yes then keep going its right and mark predecessor
 => if not then start exploring right and repeat

check if right exists 
 => if yes then explore and repeat
 => if not then got to predecessor 





*/