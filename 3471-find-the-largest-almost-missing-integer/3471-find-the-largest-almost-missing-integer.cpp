class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int i=0,j=0;
        unordered_map<int,int> mp;
        unordered_map<int,int> globalMp;
        while(k--) {
            mp[nums[j]]++;
            j++;
        }

        while(j<=nums.size()) {
            for(auto [num,count]:mp) {
                globalMp[num]++;
            }

            if(j==nums.size()) break;
            mp[nums[i]]--;if(mp[nums[i]]==0) mp.erase(nums[i]); i++;
            mp[nums[j]]++; j++;
        }

        int ans = -1;
        for(auto [num,count]:globalMp) {
            if(count==1) ans = max(ans,num);
        }
        return ans;
    }
};


/*

Global Map ->  keep track of every number that appears in  array and how many times it appears in a k sized subarray. 

map -> 
a->

a   b   c   d   e   f   g   h   i   j
                            i
                                        j

k = 4

Edge Case=>
[0,0] 
k = 2



*/