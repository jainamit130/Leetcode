class Solution {
public:
    string stringHash(string s, int k) {
        string ans="";
        int sum=0;
        for(int i=0;i<s.length();i++){
            sum+=s[i]-'a';
            if((i+1)%k==0){
                ans+=(char)(sum%26+'a');
                sum=0;
            }
        }
        return ans;
    }
};

/*

s = "abcd", k = 2

z   b               c   d
25   1               2   3
26%26=0                 5

a                       f

af

*/