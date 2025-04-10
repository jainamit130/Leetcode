class Solution {
public:
    int strStr(string haystack, string needle) {
        int lc=needle.length();
        int c=0;
        for(int i=0;i<haystack.length();i++){
            if(haystack[i]==needle[c]){
                c++;
                cout<<c;
                if(lc==c)
                    return i-lc+1;
            }else{
                i=i-c;
                c=0;
            }
        }
        return -1;
    }
};