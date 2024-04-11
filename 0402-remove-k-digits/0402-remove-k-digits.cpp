class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int> st;
        if(k==num.length())
            return "0";
        int lock=0;
        for(auto c:num){
            int n=c-'0';
            if(st.size()==k && lock==0)
                lock=1;
            if(lock==0){
                while(!st.empty() && st.top()>n){
                    st.pop();
                }
            } else {
                while(st.size()==k && st.top()>n){
                    st.pop();
                }
            }
            st.push(n);
        }
        string ans="";
        while(!st.empty()){
            ans+=to_string(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        string finalAns="";
        for(auto c:ans){
            if(finalAns.length()==0 && c=='0'){
                continue;
            }
            finalAns+=c;
        }
        if(finalAns.length()==0)
            return "0";
        return finalAns;
    }
};




/*


1   4   3   2   2   1   9
                        i
Stack: 1    2   1   9




*/