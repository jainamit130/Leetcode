class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans = 0;
        for(auto word:words) {
            if(pref.length()<=word.length() && pref==word.substr(0,pref.length())) 
                ans++;
        }
        return ans;
    }
};