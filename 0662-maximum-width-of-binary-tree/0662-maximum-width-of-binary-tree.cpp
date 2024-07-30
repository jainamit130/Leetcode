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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,long long>> q;
        q.push({root,1});
        int ans=1;
        while(!q.empty()){
            int size=q.size();
            long long minIndex = q.front().second;
            int firstVal=-1;       
            while(size){
                TreeNode* node=q.front().first;
                int num=q.front().second-minIndex;
                q.pop();
                size--;
                if(node->left){
                    q.push({node->left,2*num});
                } 
                if(node->right){
                    q.push({node->right,2*num+1});
                } 
                if(firstVal==-1){
                    firstVal=num;
                } else {
                    ans=max(ans,num-firstVal+1);
                }
            }
        }
        return ans;
    }
};