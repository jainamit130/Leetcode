class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int ans=0;
        for(int i=0;i<words.size();i++){
            for(int j=i+1;j<words.size();j++){
                if (words[j].substr(0,words[i].length())==words[i] && words[j].substr(words[j].length()-words[i].length(),words[i].length())==words[i])
                    ans++;
            }
        }
        return ans;
    }
};