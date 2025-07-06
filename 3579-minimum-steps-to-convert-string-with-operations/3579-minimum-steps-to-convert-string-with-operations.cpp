class Solution {
public:
    vector<int> cache;
    int minOperations(string word1, string word2) {
        cache.resize(word1.length()+1,-1);
        return solve(word1,word2,0);
    }

    int solve(string word1,string word2,int index) {
        if(index>=word1.length()) return 0;
        if(cache[index]!=-1) return cache[index];
        int ans = INT_MAX;
        string s1 = "",s2 = "";
        for(int i=index;i<word1.length();i++) {
            s1 += word1[i];
            s2 += word2[i];
            ans = min(ans,getMinOperations(s1,s2)+solve(word1,word2,i+1));
        }
        return cache[index]=ans;
    }

    int getMinOperations(string s1,string s2) {
        int op1 = replaceAndSwap(s1,s2);
        reverse(s1.begin(),s1.end());
        return min(op1,1+replaceAndSwap(s1,s2));
    }

    int replaceAndSwap(string s1,string s2) {
        vector<vector<int>> replaces(26,vector<int>(26,0));
        int op = 0;
        for(int i=0;i<s1.length();i++) {
            if(s1[i]!=s2[i]) {
                if(replaces[s1[i]-'a'][s2[i]-'a']>0) {
                    replaces[s1[i]-'a'][s2[i]-'a']--;
                } else {
                    replaces[s2[i]-'a'][s1[i]-'a']++;
                    op++;
                }
            }
        }
        return op;
    }
};


/*


Rotate + Swap -> Map to keep track of it


*/