class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> alphas(51);
        for(auto ch:s){
            if(ch>='a' && ch<='z')
                alphas[ch-'a']++;
            else {
                alphas[ch-'A'+26]++;
            }
        }
        int ans=0;
        int largestOdd=0;
        for(auto c:alphas){
            if(c%2==0)
                ans+=c;
            else {
                ans+=c-1;
                largestOdd=1;
            }
        }
        return ans+largestOdd;
    }
};


/*
3
4


*/