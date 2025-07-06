class Solution {
public:
    int minimumLength(string s) {
        int i=0,j=s.length()-1;
        while(i<j && s[i]==s[j]){
                char k=s[i];
                while(i<=j && k==s[i]){
                    i++;
                } while(i<j && k==s[j]){
                    j--;
                }
        }if(j<i)
            return 0;
        return j-i+1;
    }
};