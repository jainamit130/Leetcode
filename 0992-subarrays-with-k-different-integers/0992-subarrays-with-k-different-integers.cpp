class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int i=0,t=0,j=0;
        int ans=0;
        while(j<nums.size()){
            mp[nums[j]]++;

            while(mp.size()>k){
                mp[nums[t]]--;
                if(mp[nums[t]]==0)
                    mp.erase(nums[t]);
                t++;
                i=t;
            }

            while(mp[nums[t]]>1){
                mp[nums[t]]--;
                t++;
            }

            if(mp.size()==k)
                ans+=(t-i+1);
            j++;
        }
        return ans;
    }
};



/*
Map
1   ->  1
2   ->  2


i=far left
k=near left
j=right

1   2   1   2   3
i
        k
            j


result=1+2+
*/