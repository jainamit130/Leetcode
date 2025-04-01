class Solution {
public:
    vector<int> visited;
    string smallestNumber(string pattern) {
        int ans = INT_MAX;
        visited.resize(11,0);
        for(int i=1;i<=9;i++) {
            visited[i]=1;
            ans = min(ans,solve(pattern,0,i,i));
            visited[i]=0;
        }
        return to_string(ans);
    }

    int solve(string pattern,int index,int curr,int last) {
        if(index>=pattern.length()) return curr;

        int ans = INT_MAX;
        int lowerBound = pattern[index]=='I'?last+1:1;
        int upperBound = pattern[index]=='I'?9:last-1;
        for(int i=lowerBound;i<=upperBound;i++) {
            if(visited[i]==0) {
                visited[i]=1;
                ans = min(ans,solve(pattern,index+1,curr*10+i,i));
                visited[i]=0;
            } 
        }
        return ans;
    }
};

/*
I   I   I   D   I   D   D   D
1   2   4   3   8   7   6   5


DD  II  DDD I
1

*/