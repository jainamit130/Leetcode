class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int ans=0;
        int depth=0;
        for(auto ch:s){
            if(ch=='('){
                depth++;
                st.push('(');
            } else if(ch==')'){
                st.pop();
                depth--;
            } else
                continue;
            ans=max(depth,ans);
        }
        return ans;
    }
};


/*
(   1   +   (   2   *   3   )   +   (   (   )   /   4   )   )   +   1
                                            i
depth: 3
stack: (    (

*/