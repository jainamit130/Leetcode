class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int ans = 0;
        int i=0,j=0;
        unordered_set<int> st;
        for(auto n:nums) st.insert(n);
        unordered_map<int,int> mp;
        while(j<nums.size()) {
            while(j<nums.size() && mp.size()<st.size()) {
                mp[nums[j]]++; j++;
            }

            while(i<j && mp.size()>=st.size()) {
                ans += nums.size()-j+1;
                mp[nums[i]]--;
                if(mp[nums[i]]==0) mp.erase(nums[i]);
                i++;
            }
        }
        return ans;
    }
};

/*

1   6   2   2   1   3   3   4   6   3   
                i
                                        j

ans = 3 + 3 + 2 + 2 

1 -> 1
2 -> 2
3 -> 2
4 -> 1
6 -> 1

1 -> 2
2 -> 2
3 -> 3
4 -> 1
6 -> 2

*/