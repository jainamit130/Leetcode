class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> ans(n);
        stack<int> st;
        ans[n-1] = prices[n-1];
        st.push(prices[n-1]);
        for(int i=n-2;i>=0;i--) {
            ans[i]=prices[i];
            if(!st.empty() && st.top()<=prices[i]) {
                ans[i] -= st.top();
            } else {
                ans[i]-=prices[i+1]-ans[i+1];
            }
            ans[i]=max(ans[i],0);
            while(!st.empty() && prices[i]>=st.top()) {
                st.pop();
            }
            st.push(prices[i]);
        }
        return ans;
    }
};


/*

8   4   6   2   3
4   2   2   0   0

Stack:  6   4



*/