class Solution {
public:
    int minimumDeletions(string s) {
        int counta=0;
        int countb=0;
        int ans=INT_MAX;
        for(int i=0;i<s.length();i++){
            if(s[i]=='b')
               countb++;
            else 
               counta++;
            if(countb==0 && counta!=0){
                counta=0;
            }
        }
        for(int i=s.length();i>=0;i--){
            if(s[i]=='b')
               countb--;
            if(s[i]=='a')
                break;
        }
        ans=min(ans,min(counta,countb));
       return ans;
    }
};






