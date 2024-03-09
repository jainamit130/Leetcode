class Solution {
public:
    int longestOnes(vector<int>&s, int k) {
        int n=s.size();
        int i=0 ,j=0;
        int ans=INT_MIN;
        while(j<n){
            if(s[j]==0 && k>0){
                j++;
                k--;
            }
            else if(s[j]==0 && k<=0){
                  while(i<j && s[i]!=0)i++;
                  i++;
                  j++;

            }
            else{
                j++;
            }

            ans=max(ans,j-i);
        }
        return ans;
    }
};