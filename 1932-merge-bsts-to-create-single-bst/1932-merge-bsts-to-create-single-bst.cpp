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
    TreeNode* canMerge(vector<TreeNode*>& trees) {
        unordered_map<int, TreeNode*> mp;
        unordered_set<int> leaves;
        int n = trees.size();
        for (int i = 0; i < n; i++) {
            mp[trees[i]->val] = trees[i];
            if (trees[i]->left) {
                leaves.insert(trees[i]->left->val);
            }
            if (trees[i]->right) {
                leaves.insert(trees[i]->right->val);
            }
        }

        int i = 0;
        TreeNode* root = NULL;
        while (i < n) {
            if (leaves.find(trees[i]->val) == leaves.end()) {
                root = trees[i];
                break;
            }
            i++;
        }
        if (root == NULL) {
            return NULL;
        }
        leaves.clear();
        unordered_map<int, vector<int>> minMax;
        unordered_map<int, int> isLeft;
        unordered_map<int, TreeNode*> parent;
        if (root->left) {
            leaves.insert(root->left->val);
            minMax[root->left->val] = {INT_MIN, root->val};
            isLeft[root->left->val] = 1;
            parent[root->left->val] = root;
        }
        if (root->right) {
            leaves.insert(root->right->val);
            minMax[root->right->val] = {root->val, INT_MAX};
            isLeft[root->right->val] = 0;
            parent[root->right->val] = root;
        }
        mp.erase(root->val);
        while (!mp.empty()) {
            bool flag = false;
            unordered_set<int> toRemove;

            for (int leaf : leaves) {
                if (mp.find(leaf) != mp.end()) {
                    TreeNode* subTree = mp[leaf];
                    int low = minMax[leaf][0];
                    int high = minMax[leaf][1];

                    if (subTree->left) {
                        int leftVal = subTree->left->val;
                        if (low < leftVal && leftVal < high &&
                            leaves.find(leftVal) == leaves.end()) {
                            leaves.insert(leftVal);
                            minMax[leftVal] = {low, subTree->val};
                            isLeft[leftVal] = 1;
                            parent[leftVal] = subTree;
                        } else {
                            return nullptr;
                        }
                    }
                    if (subTree->right) {
                        int rightVal = subTree->right->val;
                        if (low < rightVal && rightVal < high &&
                            leaves.find(rightVal) == leaves.end()) {
                            leaves.insert(rightVal);
                            minMax[rightVal] = {subTree->val, high};
                            isLeft[rightVal] = 0;
                            parent[rightVal] = subTree;
                        } else {
                            return nullptr;
                        }
                    }

                    if (isLeft[leaf]) {
                        parent[leaf]->left = subTree;
                    } else {
                        parent[leaf]->right = subTree;
                    }

                    flag = true;
                    mp.erase(subTree->val);
                    toRemove.insert(leaf);
                    break;
                }
            }

            if (!flag) {
                return nullptr;
            }

            for (int leaf : toRemove) {
                leaves.erase(leaf);
            }
        }

        return root;
    }
};