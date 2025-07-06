class Solution {
public:
    int countHomogenous(string s) {
        if(s.length()==0) return 0;
        char ch = s[0];
        int count = 1;
        int ans = 0;
        for(int i=1;i<s.length();i++) {
            if(s[i]==s[i-1]) {
                count++;
            } else {    
                ans += count*1LL*(count+1)/2;
                count = 1;
                ch = s[i];
            }
        }
        ans += count*1LL*(count+1)/2;
        return ans;
    }
};


/*





*/