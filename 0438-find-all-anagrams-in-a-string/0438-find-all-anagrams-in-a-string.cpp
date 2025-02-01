class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(p.length()>s.length()) return {};
        unordered_map<char,int> mp;
        for(auto ch:p) {
            mp[ch]++;
        }

        unordered_map<char,int> runningMap;
        int i=0,j=0;
        while(j<p.length()) {
            runningMap[s[j]]++;
            j++;
        }
        vector<int> ans;
        while(j<=s.length()) {
            if(runningMap==mp) {
                ans.push_back(i);
            }
            if(j==s.length()) break;
            runningMap[s[i]]--;
            if(runningMap[s[i]]==0) runningMap.erase(s[i]);
            runningMap[s[j]]++;
            i++,j++;
        }
        return ans;
    }
};