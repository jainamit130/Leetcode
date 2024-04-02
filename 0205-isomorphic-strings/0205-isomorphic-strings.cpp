class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> mp;
        set<char> mapped;
        for(int i=0;i<t.length();i++){
            if(mp.find(s[i])!=mp.end()){
                if(mp[s[i]]!=t[i])
                    return false;
            }
            else {
                if(mapped.find(t[i])!=mapped.end())
                    return false;
                mp[s[i]]=t[i];
                mapped.insert(t[i]);
            }
        }
        return true;
    }
};