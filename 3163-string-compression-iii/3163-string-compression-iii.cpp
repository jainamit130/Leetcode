class Solution {
public:
    string compressedString(string word) {
        int count=1;
        char last = word[0];
        string ans="";
        for(int i=1;i<=word.length();i++){
            if(i<word.length() && word[i]==last){
                count++;
                if(count==9){
                    ans+="9";
                    ans+=last;
                    count=0;
                    last='*';
                }
            } else {
                if(count>0){
                    ans+=to_string(count)+last;
                }
                last=word[i];
                count=1;
            }
        }
        return ans;
    }
};