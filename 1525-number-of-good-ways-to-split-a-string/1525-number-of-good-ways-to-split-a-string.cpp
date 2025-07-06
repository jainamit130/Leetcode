class Solution {
public:
    int numSplits(string s) {
        vector<int> left(26);
        vector<int> right(26);
        for(auto ch:s){
            right[ch-'a']++;
        }
        int ans=0;
        for(int i=0;i<s.length()-1;i++){
            left[s[i]-'a']++;
            right[s[i]-'a']--;
            int a=0,b=0;
            for(int i=0;i<26;i++){
                if(left[i]>0){
                    a++;
                }
                if(right[i]>0){
                    b++;
                }
            }
            if(a==b){
                ans++;
            }
        }
        return ans;
    }
};


/*

a   a   c   a   b   a
1   1   2   2   3   3

0   0   





*/