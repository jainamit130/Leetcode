class Solution {
public:
    int numSteps(string s) {
        int ans=0;
        while(s.length()>1){
            if(s.back()=='0'){
                ans++;
                s.pop_back();
            } else {
                int i=s.length()-1;
                s[i]='0';
                i--;
                while(i>=0 && s[i]=='1'){
                    s[i]='0';
                    i--;
                }
                if(i==-1){
                    s[0]='1';
                    ans++;
                    s.push_back('0');
                } else {
                    s[i]='1';
                    ans++;
                }
            }
        }
        return ans;
    }
};


/*

1   1   0   1
1   1   1   0
1   1   1
1   0   0   0
1   0   0
1   0
1




0   1   1   1   1   

1   0   0   0   0

1   0   0   0

1   0   0

1   0

1

*/