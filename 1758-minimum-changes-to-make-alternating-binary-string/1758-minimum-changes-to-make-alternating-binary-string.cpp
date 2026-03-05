class Solution {
public:
    int minOperations(string s) {
        int even0 = 0;
        int even1 = 0;
        for(int i=0;i<s.length();i++) {
            if(i%2==0) {
                even1 += s[i]=='0';
                even0 += s[i]=='1';
            } else {
                even1 += s[i]=='1';
                even0 += s[i]=='0';
            }
        }
        return min(even0,even1);
    }
};

/*
010101

101010

*/