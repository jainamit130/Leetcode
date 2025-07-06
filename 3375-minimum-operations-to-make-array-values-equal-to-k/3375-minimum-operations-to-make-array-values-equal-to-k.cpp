class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> st;
        for(auto n:nums) {
            if(n<k){
                return -1;
            }
            st.insert(n);
        }

        int ans =0;
        for(auto n:st) {
            if(n!=k){
                ans++;
            }
        }
        return ans;
    }
};