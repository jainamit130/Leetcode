class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(!((str1+str2)==(str2+str1)))
            return "";
        string pattern="";
        string ans="";
        int i=0;
        while(i<str1.length() && i<str2.length()){
            if(str1[i]==str2[i]){
                pattern+=str1[i];
            } else {
                return "";
            }
            string a="";
            string b="";
            while(a.length()<str1.length()){
                a+=pattern;
            }
            while(b.length()<str2.length()){
                b+=pattern;
            }
            if(a==str1 && b==str2)
                ans=ans.length()<pattern.length()?pattern:ans;
            i++;
        }
        return ans;
    }
};