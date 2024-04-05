class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        for(char c:s){
            int val;
            if(c>= 97 && c<=122)
                val=c-32;
            else
                val=c+32;
            char ch=val;
            if(!st.empty() && st.top()==ch)
                st.pop();
            else 
                st.push(c);
        }
        string ans;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};