class Solution {
public:
    string largestGoodInteger(string num) {
        string ans = "";
        int len = 0;
        for(int i=0;i<=num.length()-3;i++) {
            string str = num.substr(i,3);
            if(str[0]==str[1] && str[1]==str[2]) {
                ans = max(ans,str);
            }
        }
        return ans;
    }
};