class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<int,int> mp;
        int i=0,j=0;
        int ans=0;
        while(j<s.length()){
            if(mp.find(s[j])!=mp.end()){
                mp.erase(s[i]);
                i++;
            }
            else if(j<s.length()){
                mp[s[j]]++;
                j++;
            }
            ans=max(ans,j-i);
        }
        return ans;
    }
};