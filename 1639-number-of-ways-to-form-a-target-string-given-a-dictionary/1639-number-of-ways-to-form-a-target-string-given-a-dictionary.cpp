class Solution {
public:
    int mod=1e9+7;
    int numWays(vector<string>& words, string target) {
        vector<vector<int>> cache(words[0].length()+1,vector<int>(target.length()+1,-1));
    map<pair<int, char>, int> mp;
    for (int i = 0; i < words.size(); i++) {
        for (int j = 0; j < words[i].length(); j++) {
            mp[{j, words[i][j]}]++;
        }
    }
        return solve(words,0,0,target,cache,mp);
    }

    int solve(vector<string>& words,int usableIndexes,int index,string target,vector<vector<int>>& cache,map<pair<int, char>, int>& mp){
        if(index>=target.size()){
            return 1;
        }
        
        if(usableIndexes>=words[0].length()){
            return 0;
        }

        if(cache[usableIndexes][index]!=-1){
            return cache[usableIndexes][index];
        }
        int ans=0;
        int ch=target[index];
        if(mp[{usableIndexes,ch}]!=0)
            ans=(ans+mp[{usableIndexes,ch}]*(long long)solve(words,usableIndexes+1,index+1,target,cache,mp))%mod;
        ans=ans+(long long)solve(words,usableIndexes+1,index,target,cache,mp)%mod;
        return cache[usableIndexes][index]=ans;
    }
};

/*

ch, i

if(character from string i matches then i can skip or take from any of the string)


    0   1   2   3
0   a   c   c   a
1   b   b   b   b
2   c   a   c   a

0   0   0
0   0   1
0   0   2
0   1   1
0   1   2
0   2   2
1   1   1
1   1   2
1   2   2
2   2   2

0   1   2
a   b   c

0   1   3


0   2   3

1   2   3


*/