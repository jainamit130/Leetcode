class Solution {
public:
    int minValidStrings(vector<string>& words, string target) {
        int len = target.length()-1;
        int n = words.size();
        vector<vector<int>> lps(n);
        for(int i=0;i<n;i++){
            vector<int> temp(words[i].length()+len+1);
            calcLps(temp,words[i]+target);
            lps[i]=temp;
        }
        int ans=0;
        while(len>=0){
            int match = 0;
            for(int i=0;i<words.size();i++){
                int currIndex = words[i].length()+len;
                match=max(match,lps[i][currIndex]);
            }
            ans++;
            if(match==0){
                return -1;
            }
            len-=match;
        }
        return ans;
    }

    void calcLps(vector<int>& ans,string pattern){
        int len=0;
        int i=1;
        while(i<pattern.length()){
            if(pattern[i]==pattern[len]){
                len++;
                ans[i]=len;
                i++;
            } else {
                if(len==0){
                    ans[i]=0;
                    i++;
                } else {
                    len=ans[len-1];
                }
            }
        }
        return;
    }
};



/*

a   a   b   c   d   a   b   c
i

pattern : a
length: 1




*/