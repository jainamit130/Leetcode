class Solution {
public:
    int numberOfGoodPartitions(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++)
            mp[nums[i]]=i;

        int i=0;
        int j=mp[nums[0]];
        int ans=1;
        while(i<nums.size()){
            if(i>j)
                ans*=2;
            j=max(j,mp[nums[i]]);
            i++;
        }
        return ans;
    }
};



/*
map
1 -> 2
5 -> 3
6 -> 4

1   5   1   5   6
            i

1   5   1   |   

*/