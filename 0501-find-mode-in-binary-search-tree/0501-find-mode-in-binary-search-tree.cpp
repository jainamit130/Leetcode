/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int maxFreq = 1;
    int val = INT_MAX;
    vector<int> ans;
    int count = 0;
    vector<int> findMode(TreeNode* root) {
        while (root) {
            if (root->left) {
                TreeNode* predecessor = root->left;
                while (predecessor->right && predecessor->right != root) {
                    predecessor = predecessor->right;
                }

                if (!predecessor->right) {
                    predecessor->right = root;
                    root = root->left;
                } else {
                    predecessor->right = NULL;
                    processFreq(root);
                    root = root->right;
                }
            } else {
                processFreq(root);
                root = root->right;
            }
        }
        processFreq(root);
        return ans;
    }

    void processFreq(TreeNode* root) {
        if (!root || root->val != val) {
            if (maxFreq == count) {
                ans.push_back(val);
            } else if (maxFreq < count) {
                maxFreq = count;
                ans.clear();
                ans.push_back(val);
            }
            if(!root) return ;
            count = 1;
            val = root->val;
        } else {
            count++;
        }
    }
};