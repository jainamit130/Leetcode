class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans="";
        int i=0;
        int j=0;
        int k=0;
        while(i<word1.length() && j<word2.length()){
            if(k%2==0){
                ans+=word1[i];
                k++;i++;
            } else {
                ans+=word2[j];
                k++;j++;
            }
        }
        while(i<word1.length()){
            ans+=word1[i];i++;
        }
        while(j<word2.length()){
            ans+=word2[j];j++;
        }
        return ans;
    }
};