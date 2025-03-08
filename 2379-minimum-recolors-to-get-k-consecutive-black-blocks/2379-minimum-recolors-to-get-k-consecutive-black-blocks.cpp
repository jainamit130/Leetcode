class Solution {
public:
    int minimumRecolors(string s, int k) {
        int i = 0 , j = 0 , n = s.length(), curr = 0 , ans = INT_MAX;

        while(j<n){
            if(s[j] == 'W'){
                curr++;
            }
            if((j-i+1) < k){
                j++;
            }
            else{
                ans = min(ans,curr);
                j++;
                if(s[i]=='W'){
                    curr--;
                }
                i++;
            }
        }
        return ans;   
    }
};