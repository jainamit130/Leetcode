class Solution {
public:
    string findValidPair(string s) {
        unordered_map<char,int> freq;
        for(auto ch:s) {
            freq[ch]++;
        }

        for(int i=0;i<s.length()-1;i++) {
            char ch = s[i];
            char ch1 = s[i+1];
            if(ch!=ch1 && freq[ch]==(int)(ch-'0') && freq[ch1]==(int)(ch1-'0')) {
                string ans = "";
                ans.push_back(ch);
                ans.push_back(ch1);
                return ans;
            }
        }
        return "";
    }
};