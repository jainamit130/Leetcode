class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> preMaxVal(1,INT_MIN);
        vector<int> postMaxVal(1,INT_MIN);
        for(int i=0;i<n-1;i++) {
            preMaxVal.push_back(max(preMaxVal.back(),nums[i]));
            postMaxVal.push_back(max(postMaxVal.back(),nums[n-i-1]));
        }
        long long ans = 0;
        for(int i=1;i<n-1;i++) {
            ans = max(ans,(preMaxVal[i]-nums[i])*1LL*postMaxVal[n-i-1]);
        }
        return ans;
    }
};