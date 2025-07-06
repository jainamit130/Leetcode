class Solution {
public:
    bool canConstruct(string s, int k) {
        vector<int> mp(26);
        for(auto ch:s) {
            mp[ch-'a']++;
        }
        int oddCount = 0;
        int evenCount = 0;
        int totalCount = 0;
        for(auto& count:mp) {
            if(count%2==1) {
                oddCount++;
            } 

            if(count>=2) {
                evenCount++;
            }

            totalCount+=count;
        }
        return totalCount>=k && max(oddCount-evenCount,0)+min(evenCount,oddCount)<=k;
    }
};


