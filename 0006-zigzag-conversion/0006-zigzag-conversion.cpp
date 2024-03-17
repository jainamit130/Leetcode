class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;
        int i = 0;
        string ans="";
        while (i < numRows) {
            int j=i;
            bool middle = true;
            while (j < s.length()) {
                ans+=s[j];
                if (i==0 || i==numRows-1) {
                        j += (2 * (numRows - 1));
                } else {
                    if (middle){
                        j += (2*(numRows-1-i));
                        middle=!middle;
                    } else {
                        j+=2*(i);
                        middle=!middle;
                    }
                }
            }
            i++;
        }
        return ans;
    }
};