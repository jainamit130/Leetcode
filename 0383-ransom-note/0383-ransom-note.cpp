class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> mp;
        for(auto m:magazine) mp[m]++;
        for(auto r:ransomNote) {
            if(mp.find(r)!=mp.end()) {mp[r]--;if(mp[r]==0) mp.erase(r);}
            else return false;
        }
        return true;
    }
};