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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        vector<int> values;
        while(!q.empty()) {
            int size = q.size();
            if(level%2==0) {
                values.clear();
            }
            while(size) {
                TreeNode* node = q.front();
                q.pop();
                size--;
                if(level%2!=0) {
                    node->val = values.back();
                    values.pop_back();
                }
                if(node->left) {
                    if(level%2==0) {
                        values.push_back(node->left->val);
                        values.push_back(node->right->val);
                    }
                    q.push(node->left);
                    q.push(node->right);
                }
            }
            level++;
        }
        return root;
    }
};