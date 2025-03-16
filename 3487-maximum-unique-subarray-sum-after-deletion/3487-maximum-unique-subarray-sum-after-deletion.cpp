class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> st;
        int allNegCheck = 0;
        int smallestNeg = 0;
        int ans = 0;
        for(auto n:nums) {
            smallestNeg = max(smallestNeg,n);
            if(n<0 || st.find(n)!=st.end()) continue;
            allNegCheck = 1;
            st.insert(n);
            ans += n;
        }

        if(allNegCheck) return smallestNeg;
        return ans;
    }
};