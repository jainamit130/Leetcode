class Solution {
public:
    string removeKdigits(string num, int k) {
        int k2 = k;
        int n = num.size();
        stack<char> st;

        //removing k digits
        for(int i=0; i<n; i++){
            if(st.empty()){
                st.push(num[i]);
            }
            else{
                if(num[i] >= st.top()){
                    st.push(num[i]);
                }
                else{
                    while(!st.empty() && k > 0 && st.top() > num[i]){
                        k--;
                        st.pop();
                    }
                    st.push(num[i]);
                }
            }
        }

        while(!st.empty() && k > 0){
            k--;
            st.pop();
        }

        string ans = "";
        bool leadRemoved = false;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        //removing leading zeros
        for(int i=0; i<ans.size(); i++){
            st.push(ans[i]);
        }
        ans = "";

        while(!st.empty()){
            if(st.top() == '0' && !leadRemoved){
                st.pop();
            }
            else{
                leadRemoved = true;
                ans.push_back(st.top());
                st.pop();
            }
        }

        if(ans.size() == 0){
            return "0";
        }

        return ans;
    }
};