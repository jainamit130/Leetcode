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
class FindElements {
public:
    unordered_set<int> st;
    FindElements(TreeNode* root) {
        solve(root,0);
    }

    void solve(TreeNode* root, int val) {
        if(!root) return;
        root->val = val;
        st.insert(val); 
        if(root->left) {
            solve(root->left,2*val+1);
        }
        if(root->right) {
            solve(root->right,2*val+2);
        } 
        return;
    }
    
    bool find(int target) {
        return st.find(target)!=st.end();
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */