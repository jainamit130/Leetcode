class Solution {
public:
    int strangePrinter(string s) {
        int n=s.length();
        vector<vector<int>> cache(n+1,vector<int>(n+1,-1));
        return solve(s,0,n-1,cache);
    }

    int solve(string s,int start,int end,vector<vector<int>>& cache){
        if(start==end){
            return 1;
        }

        if(start>end){
            return 0;
        }

        if(cache[start][end]!=-1){
            return cache[start][end];
        }

        int basic=INT_MAX;
        int greedy=INT_MAX;
        int i=start;
        while(i<=end && s[start]==s[i]){
            i++;
        }
        if(i>end){
            return 1;
        }
        basic=min(basic,1+solve(s,i,end,cache));
        for(int j=i;j<=end;j++){
            if(s[j]==s[start])
                greedy=min(greedy,solve(s,i,j-1,cache)+solve(s,j,end,cache));
        }
        return cache[start][end]=min(basic,greedy);
    }
};


/*

b   a   a   a   a   a   b   b   a   b


b   b   b   b   b   b   b   b   b   b





*/