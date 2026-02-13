class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length();
        int ans = 1;
        for(int i=0;i<n;i++) {
            unordered_map<char,int> mp;
            for(int j=i;j<n;j++) {
                mp[s[j]]++;
                int freq = 0;
                int flag = 1;
                for(char ch='a';ch<='z';ch++) {
                    if(mp[ch]==0) continue;
                    if(freq==0) freq = mp[ch];
                    else if(freq!=0 && freq!=mp[ch]) {
                        flag = 0; break;
                    } 
                }
                if(flag) ans = max(ans,j-i+1);
            }
        }
        return ans;
    }
};