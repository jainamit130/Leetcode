class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string common=strs[0];
        for(int j=1;j<strs.size();j++){
            int i=0;
            string subCommon="";
            while(i<strs[j].length() && i<common.length()){
                if(strs[j][i]!=common[i])
                    break;
                subCommon+=common[i]; 
                i++;
            }
            common=subCommon;
            if(common=="")
                break;
        }
        return common;
    }
};