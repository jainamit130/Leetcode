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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        int level = 0;
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> ans;
        while(!q.empty()) {
            vector<int> subAns;
            int size = q.size();
            while(size) {
                TreeNode* node = q.front();
                subAns.push_back(node->val);
                q.pop(); size--; 
                if(node->left) {
                    q.push(node->left);
                } 
                if(node->right) {
                    q.push(node->right);
                }
            }
            if(level%2!=0) reverse(subAns.begin(),subAns.end());
            ans.push_back(subAns);
            level++;
        }
        return ans;
    }
};


/*
              1
          2      3 
        4   5   N  6
      7  8  N 9    10  11

Deque<TreeNode> =>          c41  c42  c31  c32   c21 c22   c11 c12 
push from the back
 for l to r pop from front
 for r to l pop from back

1. root node pushed as initial value of deque




*/