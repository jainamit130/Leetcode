class Solution {
public:
    string getSmallestString(string s, int k) {
        int n = s.size();
        
        auto distance = [](char a, char b) {
            return min((b - a + 26) % 26, (a - b + 26) % 26);
        };
        
        for(int i=0;i<s.length() && k>0;i++){
            char ch=s[i];
            //try to change it to a
            int t=distance(s[i],'a');
            if(t>k){
                s[i]=s[i]-k;
                k=0;
            }
            else {
                s[i]='a';
                k-=t;
            }
        }
        return s;
    }
};
