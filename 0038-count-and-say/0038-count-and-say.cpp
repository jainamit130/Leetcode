class Solution {
public:
    string countAndSay(int n) {
        string ans="1"; 
        for(int i=2;i<=n;i++){
            ans= cAndS(ans);
            // cout<<ans<<endl;
        } 
        return ans;
    }

    string cAndS (string ans){
       int i=0;
       string nextAns;
       while(i<ans.length()){
           int j=i,count=1;
           while(ans[j]==ans[j+1]){
               count++;
               j++;
           }
        //    cout<<ans[j]<<endl;
           nextAns+=to_string(count)+ans[j];
        //    cout<<"Next ans = "<<nextAns<<endl;
            i=j+1;
       }
        return nextAns;
    }
};
