class Solution {
public:
    int count=0;
    int pathSum(TreeNode* root, int targetSum) {
        dfsSolve(root,targetSum);
        return count/2;
    }

    void dfsSolve(TreeNode* root,int targetSum){
        if(!root)
            return;

        solve(root->left,targetSum-root->val);
        solve(root->right,targetSum-root->val);
        dfsSolve(root->left,targetSum);
        dfsSolve(root->right,targetSum);
        return;
    }

    void solve(TreeNode* root,long long targetSum){
        if(targetSum==0)
            count++;

        if(!root)
            return;

        solve(root->left,targetSum-root->val);
        solve(root->right,targetSum-root->val);
        return;
    }
};