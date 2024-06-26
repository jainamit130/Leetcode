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
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> nodes;
        getNodes(root,nodes);
        sort(nodes.begin(),nodes.end());
        return generateBST(nodes,0,nodes.size()-1);
    }

    TreeNode* generateBST(vector<int>& nodes,int start,int end){
        if(start>end){
            return NULL;
        }

        TreeNode* root=new TreeNode();
        int mid= (start+end)/2;
        root->val=nodes[mid];
        root->left=generateBST(nodes,start,mid-1);
        root->right=generateBST(nodes,mid+1,end);
        return root;
    }

    void getNodes(TreeNode* root, vector<int>& nodes){
        if(!root){
            return;
        }

        getNodes(root->left,nodes);
        nodes.push_back(root->val);
        getNodes(root->right,nodes);
        return;
    }
};