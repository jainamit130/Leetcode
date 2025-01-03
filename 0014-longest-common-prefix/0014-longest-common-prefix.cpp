class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix=strs[0];
        for(int i=1;i<strs.size();i++) {
            string pre = "";
            int k=0;
            for(int j=0;j<strs[i].length();j++) {
                if(k<prefix.length() && prefix[k]==strs[i][j]) {
                    pre += prefix[k];
                    k++;
                } else {
                    break;
                }
            }
            prefix=pre;
        }
        return prefix;
    }
};