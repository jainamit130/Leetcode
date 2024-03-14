class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> prefix;
        prefix[0]=1;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            prefix[sum]++;
        }
        int ans=0;
        unordered_set<int> visited;
        for(auto [first,count]:prefix){
            int second=goal+first;
            if(visited.find(first)!=visited.end())
                continue;
            if (first==second)
                ans+=count*(count-1)/2;
            else if(prefix.find(second)!=prefix.end())
                ans+=prefix[first]*prefix[second];
            visited.insert(first);
        }
        return ans;
    }
};
