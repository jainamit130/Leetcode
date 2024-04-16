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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        TreeNode* ans=root;
        queue<TreeNode*> q;
        if(depth==1){
            TreeNode* n=new TreeNode(val);
            n->left=root;
            return n;
        }
        q.push(root);
        int d=1;
        int flag=0;
        while(!q.empty()){
            int size=q.size();
            while(size){
                TreeNode* top=q.front();
                if(d==depth-1){
                   flag=1;
                   break;
                }
                q.pop();
                size--;
                if(top->left)
                    q.push(top->left);
                if(top->right)
                    q.push(top->right);
            }
            if(flag==1)
                break;
            d++;
        }
         while(!q.empty()){
            TreeNode* top=q.front();
            q.pop();
            TreeNode* temp=top->left;
            TreeNode* n1=new TreeNode(val);
            TreeNode* n2=new TreeNode(val);
            top->left=n1;
            n1->left=temp;
            temp=top->right;
            top->right=n2;
            n2->right=temp;
        }
        return ans;
    }
};