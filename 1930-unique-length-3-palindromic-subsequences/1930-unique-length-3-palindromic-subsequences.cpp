class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<pair<int,vector<int>>> mp(26);
        vector<int> ans(26);
        for(int i=0;i<s.length();i++) {
            if(mp[s[i]-'a'].first) {
                int subAns = 0;
                for(int j=0;j<26;j++) {
                    subAns+=mp[s[i]-'a'].second[j];
                }
                ans[s[i]-'a']=subAns;
            }
            for(int j=0;j<26;j++) {
                if(mp[j].first) {
                    mp[j].second[s[i]-'a']=1;
                }
            }
            if(mp[s[i]-'a'].first==0) {
                mp[s[i]-'a'].first=1;
                mp[s[i]-'a'].second.resize(26);
            }
        }
        int result = 0;
        for(auto subAns:ans) {
            result+=subAns;
        }
        return result;
    }
};