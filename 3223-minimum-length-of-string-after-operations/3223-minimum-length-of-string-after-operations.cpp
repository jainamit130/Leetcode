class Solution {
public:
    int minimumLength(string s) {
        vector<int> bucket(26);
        for(int i=0;i<s.length();i++){
            bucket[s[i]-'a']++;
        }
        int ans=0;
        for(int i=0;i<26;i++){
            while(bucket[i]>2){
                bucket[i]-=2;
            }
            ans+=bucket[i];
        }
        return ans;
    }
};