class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix=strs[0];
        for(int i=1;i<strs.size();i++) {
            string pre = "";
            for(int j=0;j<prefix.length();j++) {
                if(prefix[j]==strs[i][j]) {
                    pre += prefix[j];
                } else {
                    break;
                }
            }
            prefix=pre;
        }
        return prefix;
    }
};