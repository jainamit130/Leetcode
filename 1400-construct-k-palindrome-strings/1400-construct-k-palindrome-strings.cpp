class Solution {
public:
    bool canConstruct(string s, int k) {
        vector<int> mp(26);
        for(auto ch:s) {
            mp[ch-'a']++;
        }
        int oddCount = 0;
        int possibleCount = 0;
        int totalCount = 0;
        for(auto& count:mp) {
            if(count%2==1) {
                oddCount++;
            } 

            if(count>=2) {
                possibleCount++;
            }

            totalCount+=count;
        }
        return totalCount>=k && max(oddCount-possibleCount,0)+min(possibleCount,oddCount)<=k;
    }
};


