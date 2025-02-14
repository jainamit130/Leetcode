class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        unordered_map<string,int> strFreq;
        for(int size = minSize; size<=maxSize; size++) {
            int i=0,j=0;
            unordered_map<char,int> freq;
            while(j<size) {
                freq[s[j]]++;
                j++;
            }
            while(j<=s.length()) {
                if(freq.size()<=maxLetters) {
                    string str = s.substr(i,size);
                    strFreq[str]++;
                }
                if(j==s.length()) break;
                freq[s[i]]--; 
                if(freq[s[i]]==0) freq.erase(s[i]);
                i++;
                freq[s[j]]++; j++;
            }
        }
        int ans = 0;
        for(auto [str,count]:strFreq) {
            ans = max(ans,count);
        }
        return ans;
    }
};

/*

a   a   b   a   b   c   a   a   b
0   1   2   3   4   5   6   7   8


4-8

x   x   x   x   x   x   x   x   x   x   x   x   x   x




*/