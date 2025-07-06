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
    int rob(TreeNode* root) {
        vector<int> options = travel(root);
        return max(options[0], options[1]);
    }

    vector<int> travel(TreeNode* root) {
        // Base case. just return {0,0} as you cannot rob anything
        if (root == NULL)
            return {0,0};

        vector<int> left_node_choices = travel(root->left);
        vector<int> right_node_choices = travel(root->right);
        vector<int> options(2);

        // Store value if looted in [0]
        options[0] = root->val + left_node_choices[1] + right_node_choices[1];

        // Store value if skipped in [1]
        options[1] = max(left_node_choices[0], left_node_choices[1]) +
                     max(right_node_choices[0], right_node_choices[1]);

        return options;
    }
};