class Solution {
public:
    int characterReplacement(string s, int k) {
        int i=0,j=0;
        vector<int> freq(26);
        int ans = 0; 

        auto isValid = [&](int size) {
            int maxNum = 0;
            for(int i=0;i<freq.size();i++) {
                maxNum=max(freq[i],maxNum);
            }
            return size-maxNum<=k;
        };

        while(j<s.length()) {
            while(j<s.length()) {
                freq[s[j]-'A']++;
                j++;
                if(!isValid(j-i)) break;
                ans = max(ans,j-i);
            } 
            if(j==s.length()) { if(isValid(j-i)) ans=max(ans,j-i); break; }
            while(i<=j && !isValid(j-i)) {
                freq[s[i]-'A']--;
                i++;
            }
        }
        return ans;
    }
};