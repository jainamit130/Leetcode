/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    using pni=pair<Node*,int>;
    vector<int> postorder(Node* root) {
        if(root==NULL){
            return {};
        }
        stack<pni> st;
        vector<int> ans;
        st.push({root,0});
        while(!st.empty()){
            int index=st.top().second;
            Node* parent=st.top().first;
            st.pop();
            if(index==parent->children.size()){
                ans.push_back(parent->val);
            } else {
                st.push({parent,index+1});
                st.push({parent->children[index],0});
            }
        }
        return ans;
    }
};