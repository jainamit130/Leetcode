class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto n:nums){
            mp[n]++;
        }

        int ans = 0;
        for(int i=0;i<nums.size();i+=3) {
            if(mp.size()==nums.size()-i){
                return ans;
            } else{
                if(i+2<nums.size()) {
                    removeFromMap(mp,nums[i]);
                    removeFromMap(mp,nums[i+1]);
                    removeFromMap(mp,nums[i+2]);
                }
                ans++;
            } 
        }
        return ans;
    }

    void removeFromMap(unordered_map<int,int>& mp,int num) {
        mp[num]--;
        if(mp[num]==0) {
            mp.erase(num);
        }
    }
};


/*

4   4
i


*/