class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int> st;
        for(auto c:num){
            int n=c-'0';
            while(k>0 && !st.empty() && st.top()>n){
                k--;
                st.pop();
            }
            st.push(n);

        }
        string ans="";
        while(!st.empty()){
            if(k>0){
                st.pop();
                k--;
                continue;
            } else {
                ans+=to_string(st.top());
                st.pop();
            }
        }
        reverse(ans.begin(),ans.end());
        string finalAns="";
        for(auto c:ans){
            if(finalAns.length()==0 && c=='0')
                continue;
            else 
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