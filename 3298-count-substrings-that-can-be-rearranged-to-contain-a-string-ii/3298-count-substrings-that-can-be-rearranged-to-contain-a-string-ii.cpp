class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        unordered_map<char, int> missing;
        unordered_map<char, int> present;
        unordered_map<char, int> extra;
        int m = word1.length();
        int n = word2.length();
        for (int i = 0; i < n; i++) {
            missing[word2[i]]++;
        }
        long long ans = 0;
        int i=0;
        int j = 0;
        while (i <= m-n) {
            while(j<m){
                if(missing.empty()){
                    break;
                }
                if(missing.find(word1[j])!=missing.end()){
                    missing[word1[j]]--;
                    present[word1[j]]++;
                    if(missing[word1[j]]==0){
                        missing.erase(word1[j]);
                    }
                } else {
                    extra[word1[j]]++;
                }
                j++;
            }
            if(missing.empty()){
                ans+=m-j+1;
            }

            if(present.find(word1[i])!=present.end()){
                if(extra.find(word1[i])!=extra.end()){
                    extra[word1[i]]--;
                    if(extra[word1[i]]==0){
                        extra.erase(word1[i]);
                    }
                } else {
                    present[word1[i]]--;
                    missing[word1[i]]++;
                    if(present[word1[i]]==0){
                        present.erase(word1[i]);
                    }
                }
            }
            i++;
        }
        return ans;
    }
};

/*
d   e   d   e   d   d   d   e   e   e   d
4   4   3   3   2   2   2   2   0   0   0


e   e   d   d   e   e   d   e   d
6   6   5   3   1   1   1   0   0

dde

*/