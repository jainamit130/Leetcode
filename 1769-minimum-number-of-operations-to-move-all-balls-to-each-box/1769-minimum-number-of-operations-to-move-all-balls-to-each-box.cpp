class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> prefix,suffix,ans;
        solve(boxes,prefix,suffix);
        int n = boxes.size();
        for(int i=0;i<n;i++) {
            ans.push_back(prefix[i]+suffix[n-i-1]);
        }
        return ans;
    }

    void solve(string& nums,vector<int>& prefix,vector<int>& suffix) {
        int prefixCount=0,suffixCount = 0;
        int prefixAns=0,suffixAns = 0;
        int n = nums.length();
        for(int i=0;i<n;i++) {
            prefixAns+=prefixCount;
            suffixAns+=suffixCount;
            if(nums[i]=='1') {
                prefixCount++;
            }
            if(nums[n-i-1]=='1') {
                suffixCount++;
            }
            prefix.push_back(prefixAns);
            suffix.push_back(suffixAns);
        }
        return;
    }
};