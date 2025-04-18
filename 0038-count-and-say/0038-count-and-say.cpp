class Solution {
public:
    string countAndSay(int n) {
        int i = 1;
        string ans = "1";
        for(int i=2;i<=n;i++) {
            ans = getRle(ans);
        }
        return ans;
    }

    string getRle(string str) {
        int count = 1;
        string ans;
        for(int i=1;i<=str.length();i++) {
            if(i<str.length() && str[i]==str[i-1]) {
                count++;
            } else {
                ans += to_string(count)+str[i-1];
                count = 1;
            }
        }
        return ans;
    }
};

/*


Given: int n => always positive
Told => base case => countAndSay(1) = "1"
Return a string

Ex:

11 => 21
12 => 1112

*/