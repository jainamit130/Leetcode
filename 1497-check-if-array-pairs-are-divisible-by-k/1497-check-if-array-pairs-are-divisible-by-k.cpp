class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
        for(auto n:arr){
            int mod=n%k;
            if(mod<0)
                mod+=k;
            mp[mod]++;
        }
        unordered_set<int> visited;
        for(auto [remainder,count]:mp){
            if(visited.find(remainder)!=visited.end())
                continue;
            if((2*remainder==(k) || remainder==0) && count%2==0){
                visited.insert(remainder);
                continue;
            } else {
                if(mp.find(k-remainder)!=mp.end() && mp[k-remainder]==count){
                    visited.insert(k-remainder);
                    visited.insert(remainder);
                    continue;
                }
            } 
            return false;
        }
        return true;
    }
};