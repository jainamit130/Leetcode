class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string p) {
        vector<string> ans;
        for(auto s:words) {
            if(s.length()!=p.length()) continue;
            unordered_map<char,char> mp1;
            unordered_map<char,char> mp2;
            int flag = 0;
            for(int i=0;i<s.length();i++) {
                if(mp1.find(p[i])==mp1.end() && mp2.find(s[i])==mp2.end()) {
                    mp1[p[i]]=s[i];
                    mp2[s[i]]=p[i];
                } else if(mp1.find(p[i])!=mp1.end() && mp2.find(s[i])!=mp2.end() && mp1[p[i]]==s[i] && mp2[s[i]]==p[i]) {
                   continue;
                } else {
                    flag = 1; break;
                }
            }
            if(!flag) ans.push_back(s);
        }
        return ans;
    }
};



/*

vector<string> words
string pattern

Clarifications:

1. can the match be case sensitive? yes
2. pattern cannot be empty ? yes


abc
deq
mee
aqq
dkd
ccc

abb

c -> a

a -> c


*/