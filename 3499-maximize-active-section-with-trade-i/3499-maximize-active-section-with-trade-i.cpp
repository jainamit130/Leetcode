class Solution {
public:
    int maxActiveSectionsAfterTrade(string st) {
        string s = "1"+st+"1";
        int startz = 0, endz = 0;
        int flag0 = 0, flag1 = 0;
        int maxCount = 0;
        int ones = 0;
        for(int i=0;i<s.length();i++) {
            if(s[i]=='0') {
                if(flag1) flag0 = 2; else flag0 = 1;
                endz++;
            } else {    
                if(i!=0 && i!=s.length()-1) ones++;
                if(flag0) flag1 = 1;
                if(i>0 && s[i-1]=='1') continue;
                if(flag1 && flag0==2) {
                    flag0=1;
                    maxCount = max(maxCount,startz+endz);
                }
                startz = endz;
                endz = 0;
            }
        }
        return maxCount+ones;
    }
};