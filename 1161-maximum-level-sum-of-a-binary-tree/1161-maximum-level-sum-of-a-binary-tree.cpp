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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* ptr=root;
        int maxSum=INT_MIN;
        int ans=0;
        int level=1;
        while(!q.empty()){
            int size=q.size();
            int sum=0;
            while(size){
               TreeNode* temp=q.front();
               sum+=temp->val;
               q.pop();
               size--;
               if(temp->left)
                    q.push(temp->left); 
               if(temp->right)
                    q.push(temp->right); 
            }
            if(maxSum<sum){
                maxSum=sum;
                ans=level;
            }
            level++;
        }
        return ans;
    }
};