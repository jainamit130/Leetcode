class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int m=word1.length();
        int n=word2.length();
        vector<int> dp(m+1,0);
        int j=n-1;
        for(int i=m-1;i>=0;i--){
            dp[i]=dp[i+1];
            if(j>=0 && word2[j]==word1[i]){
                dp[i]++;
                j--;
            }
        }

        j=0;
        int power=1; // have power
        vector<int> ans;
        for(int i=0;i<m && j<n;i++){
            if(word1[i]!=word2[j] && power==1 && dp[i+1]>=n-j-1){
                power=0; // power exhasted
                ans.push_back(i);
                j++;
            } else if(word1[i]==word2[j]){
                ans.push_back(i);
                j++;
            }
        }

        if(ans.size()!=n){
            return {};
        }
        return ans;
    }
};

/*

LEXOGRAPHICALLY Smallest

Power = 1


ans: 0 3 7

word1: 
a   a   a   b   b   c   c   d   d
                            i

word 2:
c   b   d
j



dp: 
2   2   2   2   2   1   1   1   1  0
            i




*/