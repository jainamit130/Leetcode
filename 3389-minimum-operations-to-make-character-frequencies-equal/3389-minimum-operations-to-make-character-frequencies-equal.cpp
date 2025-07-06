class Solution {
public:
    unordered_map<int,unordered_map<int,int>> cache;
    int makeStringGood(string s) {
        unordered_map<int,int> mp;
        int maxC = 0;
        for(auto ch:s) {
            mp[ch-'a']++;
            maxC = max(maxC,mp[ch-'a']);
        }

        int ans = INT_MAX;
        for(int i=0;i<=maxC;i++) {
            cache.clear();
            ans = min(ans,solve(mp,i,0,0));
        }

        return ans;
    }

    int solve(unordered_map<int,int>& mp,int targetFreq, int index, int leftOvers) {
        if(index>=26) {
            return 0;
        }

        int ans = INT_MAX;
        int current = mp[index];

        if(cache[index].count(leftOvers)) {
            return cache[index][leftOvers];
        }

        if(current==targetFreq) {
            ans = min(ans,solve(mp,targetFreq,index+1,0));
        } else if(current<targetFreq) {
            ans = min({ans,
                       max(targetFreq-(current+leftOvers),0) +solve(mp,targetFreq,index+1,0),
                       current+ solve(mp,targetFreq,index+1,current)});
        } else {
            ans = min(ans , current-targetFreq + solve(mp,targetFreq,index+1,current-targetFreq));
        }

        return cache[index][leftOvers]=ans;
    }
};

/*


a   a   a   b   c


Map

a -> 3
b -> 1
c -> 1

index, leftOvers

x frequency =>

ax > x
=> should not just delete
=> but convert => cost = ax-x

ax == x
=> Move forward => cost = 0

ax < x
=>  go towards x => cost = x-ax ; leftover = 0;
=>  go towards 0 => cost = ax; leftover = ax

0 -> 2*10^4

*/