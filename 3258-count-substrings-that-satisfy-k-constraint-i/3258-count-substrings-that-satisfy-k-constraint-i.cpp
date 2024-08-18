class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int i=0,j=0;
        int z=0,o=0;
        int n=s.length();
        int ans=n*(n+1)/2;
        int count=0;
        while(j<s.length()){
            if(z<=k || o<=k){
                if(s[j]=='1'){
                    o++;
                } else {
                    z++;
                }
                j++;
            } else {
                count++;
                if(s[i]=='1'){
                    o--;
                } else {
                    z--;
                }
                i++;
            }
        }
        if(j==s.length() && z>k && o>k){
            count++;
        }
        ans-=(count*(count+1)/2);
        return ans;
    }
};