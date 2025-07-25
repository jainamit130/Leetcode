class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> st;
        int allNegCheck = 0;
        int ans = 0;
        int smallestNeg = INT_MIN;
        for(auto n:nums) {
            smallestNeg = max(n,smallestNeg);
            if(n<0 || st.find(n)!=st.end()) continue;
            allNegCheck = 1;
            ans += n;
            st.insert(n);
        }

        if(allNegCheck==0) return smallestNeg;
        return ans;
    }
};