class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int i=0,j=0;
        int ans=0;
        int currCost=0;
        while(j<s.length()){
            if((currCost+abs(s[j]-t[j]))<=maxCost){
                currCost+=abs(s[j]-t[j]);
                ans=max(ans,j-i+1);
                j++;
            } else {
                currCost-=abs(s[i]-t[i]);
                i++;
            }
        }
        return ans;
    }
};


/*

a   b   c   d

b   c   d   f

0   0   1   3   6

0   1   3   6   11



*/