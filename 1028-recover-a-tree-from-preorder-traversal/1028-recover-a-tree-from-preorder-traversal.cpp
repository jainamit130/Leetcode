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
    TreeNode* recoverFromPreorder(string s) {
        stack<TreeNode*> st;
        int num=0;
        int i=0;
        while(i<s.length() && s[i]!='-'){
            num=num*10+(int)(s[i]-48);
            i++;
        }
        TreeNode* root=new TreeNode(num);
        st.push(root);
        while(!st.empty()){
            int depth=0;
            while(i<s.length() && s[i]=='-'){
                depth++;
                i++;
            }
            int num=0;
            while(i<s.length() && s[i]!='-'){
                num=num*10+(int)(s[i]-48);
                i++;
            }
            if(depth==0)
                break;
            TreeNode* node=new TreeNode(num);
            while(depth<st.size()){
                st.pop();
            }
            if(!st.top()->left){
                st.top()->left=node;
            } else {
                st.top()->right=node;
            }
            st.push(node);
        }
        return root;
    } 
};