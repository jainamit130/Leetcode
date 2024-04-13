class Solution {
public:
    int scoreOfString(string s) {
        int ans=0;
        for(int i=1;i<s.length();i++){
            ans+=abs(s[i-1]-s[i]);
        }
        return ans;
    }
};