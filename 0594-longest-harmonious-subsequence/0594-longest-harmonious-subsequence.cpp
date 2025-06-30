class Solution {
public:
    // O(nlogn) and O(1)
    int findLHS(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0,j=0;
        int ans = 0;
        while(j<nums.size()) {
            while(i<j && nums[j]-nums[i]>1) {
                i++;
            }
            if(nums[j]-nums[i]==1) {
                ans=max(ans,j-i+1);
            }
            j++;
        }
        return ans;
    }

    // // O(n) and O(n)
    // int findLHS(vector<int>& nums) {
    //     unordered_map<int,int> mp;
    //     for(auto n:nums) {
    //         mp[n]++;
    //     }
    //     int ans = 0;
    //     for(auto [num,count]: mp) {
    //         // considering it as maximum
    //         int otherNum = num-1;
    //         if(mp.find(otherNum)!=mp.end()) {
    //             ans = max(ans,mp[otherNum]+count);
    //         }
    //         // considering it as minimum
    //         otherNum = num+1;
    //         if(mp.find(otherNum)!=mp.end()) {
    //             ans = max(ans,mp[otherNum]+count);
    //         }
    //     }
    //     return ans;
    // }
};

/*

can we have negative values - yes
can a array be empty? - yes ans = 0

1   3   2   3   2   2   1   2   1   2   2




*/