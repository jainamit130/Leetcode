class Solution {
public:
    bool maxSubstringLength(string s, int k) {
        unordered_map<char,int> mp;
        for(auto ch:s) {
            mp[ch]++;
        }
        int i=0,j=0;
        int count = 0;
        while(j<s.length()) {
            if(mp[s[j]]!=1) {
                count += (j-i);
                j++;
                i=j;
            } else {
                mp[s[j]]--;
                if(mp[s[j]]==0) mp.erase(s[j]);
                j++;
            }
        }
        count+=j-i;
        int freq = 1;
        for(int i=1;i<=s.length();i++) {
            if(i<s.length() && s[i]==s[i-1]) {
                freq++;
            } else {
                if(mp[s[i-1]]==freq) {
                    count+=1;
                }
                freq = 1;
            }
        }
        return count>=k;
    }
};