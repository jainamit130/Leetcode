class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> freq(26);
        int maxCon = 0 , maxVow = 0;
        unordered_set<char> vowel = {'a','e','i','o','u'};
        for(auto& ch:s) {
            int ascii = ch-'a';
            freq[ascii]++;
            if(vowel.find(ch)!=vowel.end()) {
                if(freq[ascii]>maxVow) maxVow = freq[ascii];
            } else if(freq[ascii]>maxCon) {
                maxCon = freq[ascii];
            }
        }
        return maxCon + maxVow;
    }
};