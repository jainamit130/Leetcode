class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        int i=0;
        int count=0;
        int index=-1;

        while(i<s.length()){
            if(s[i]==' '){
                i++;
                count++;
            } else {
                s.erase(i-count,count);
                i-=count;
                count=0;
                int startIndex=i;
                while(i<s.length() && s[i]!=' '){
                    i++;
                }
                reverse(s.begin()+startIndex,s.begin()+i);
                i++;
            }
        }
        if(count>0)
            s.erase(i-count-1,count+1);
        return s;
    }
};