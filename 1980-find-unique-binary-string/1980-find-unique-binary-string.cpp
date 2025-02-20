class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n  = nums.size();
        unordered_set<string> st(nums.begin(),nums.end());
        return solve(n,st);
    }

    string solve(int n,unordered_set<string> st) {
        if(n==0) {
            return "";
        }

        string ans = "";
        // add 0
        ans="0"+solve(n-1,st);
        if(st.find(ans)==st.end()) return ans;
        // add 1
        ans = "1"+solve(n-1,st);
        if(st.find(ans)==st.end()) return ans;
        return ans;
    }
};