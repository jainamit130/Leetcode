class Solution {
public:
    int appendCharacters(string s, string t) {
        int i=0,j=0;
        int ans=t.length();
        for(int i=0;i<s.length();i++){
            if(j>=t.length())
                break;
            if(s[i]==t[j]){
                j++;
                ans--;
            }
        }
        return ans;
    }
};