class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> freq(26);
        for(auto ch:s) freq[ch-'a']++;
        for(auto ch:t) {
            if(freq[ch-'a']==0) return ch;
            freq[ch-'a']--;
        }
        return t[0];
    }
};