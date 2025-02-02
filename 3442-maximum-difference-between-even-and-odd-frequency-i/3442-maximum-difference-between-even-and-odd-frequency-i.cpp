class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char,int> freq;
        for(auto ch:s) {
            freq[ch]++;
        }
        int minEven = s.length();
        int maxEven = 0;
        int minOdd = s.length();
        int maxOdd = 0;
        for(auto [_,count]:freq) {
            if(count%2==0) {
                minEven = min(minEven,count);
                maxEven = max(maxEven,count);
            } else {
                minOdd = min(minOdd,count);
                maxOdd = max(maxOdd,count);
            }
        }
        return max(maxEven-minOdd,maxOdd-minEven);
    }
};