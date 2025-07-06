class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        int mod = 1e9+7;
        int ans = 0;
        vector<int> freq(26);
        for(auto ch:s){
            freq[ch-'a']++;
        }

        while(t--){
            int lastCount = freq[0];
            int currCount = -1;
            freq[0]=0;
            for(int i=1;i<26;i++){
                currCount=freq[i];
                freq[i]=lastCount;
                lastCount=currCount;
            }
            freq[0]=currCount%mod;
            freq[1]=(freq[1]+currCount)%mod;
        }

        for(auto count:freq){
            ans=(ans+count)%mod;
        }
        return ans;
    }
};