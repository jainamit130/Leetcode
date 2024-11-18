class Solution {
public:
    string longestPalindrome(string s) {
       int fi=0;
       int size=0;
       for(int k=0;k<s.length();k++){
           int i=k,j=k;
           while(i>-1 && j<s.length()){
               if(s[i]==s[j]){
                   if(size<(j-i+1)){
                       size=j-i+1;
                       fi=i;
                   }
                   i--;j++;
               } else 
                    break;
           }

            i=k,j=k+1;
            while(i>-1 && j<s.length()){
               if(s[i]==s[j]){
                   if(size<(j-i+1)){
                       size=j-i+1;
                       fi=i;
                   }
                   i--;
                   j++;
               } else 
                    break;
           }
       }
       return s.substr(fi,size); 
    }
};