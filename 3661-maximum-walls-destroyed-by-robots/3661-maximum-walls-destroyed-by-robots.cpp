class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = robots.size();
        sort(walls.begin(),walls.end());
        vector<int> indexes(n);
        iota(indexes.begin(),indexes.end(),0);
        sort(indexes.begin(),indexes.end(),[&](auto& lhs,auto& rhs) {
            return robots[lhs]<robots[rhs];
        });

        vector<vector<int>> dp(n+1, vector<int>(2, 0));

        for (int i = n-1; i >= 0; i--) {
            for (int prevDir = 0; prevDir < 2; prevDir++) {
                int roboIndex = indexes[i];
                int startDist = robots[roboIndex] - distance[roboIndex];
                int endDist   = robots[roboIndex] + distance[roboIndex];

                if (i >= 1) {
                    startDist = max(robots[indexes[i-1]]+1, startDist);
                    if (prevDir == 1) 
                        startDist = max(startDist, robots[indexes[i-1]] + distance[indexes[i-1]] + 1);
                }

                int ans = 0;

                int roboPosIndex = upper_bound(walls.begin(), walls.end(), robots[roboIndex]) - walls.begin();
                int startIndex   = lower_bound(walls.begin(), walls.end(), startDist) - walls.begin();
                ans = max(ans, roboPosIndex - startIndex + dp[i+1][0]);

                roboPosIndex = lower_bound(walls.begin(), walls.end(), robots[roboIndex]) - walls.begin();
                if (i < n-1) endDist = min(endDist, robots[indexes[i+1]] - 1);
                int endIndex = upper_bound(walls.begin(), walls.end(), endDist) - walls.begin();
                ans = max(ans, endIndex - roboPosIndex + dp[i+1][1]);

                dp[i][prevDir] = ans;
            }
        }
        
        return dp[0][0];


        // vector<vector<int>> cache(n+1,vector<int>(2,-1));
        // function<int(int,int)> solve = [&](int i,int prevDir) {
        //     if(i>=n) return 0;
        //     if(cache[i][prevDir]!=-1) return cache[i][prevDir];
        //     int roboIndex = indexes[i];
        //     int startDist = robots[roboIndex]-distance[roboIndex];
        //     int endDist = robots[roboIndex]+distance[roboIndex];
        //     if(i>=1) {
        //         startDist = max(robots[indexes[i-1]]+1,startDist);
        //         if(prevDir==1) startDist = max(startDist,robots[indexes[i-1]]+distance[indexes[i-1]]+1);
        //     }

        //     int ans = 0;
        //     int roboPosIndex = upper_bound(walls.begin(),walls.end(),robots[roboIndex])-walls.begin();
        //     int startIndex = lower_bound(walls.begin(),walls.end(),startDist)-walls.begin();
        //     ans = max(ans,roboPosIndex-startIndex + solve(i+1,0));
        //     roboPosIndex = lower_bound(walls.begin(),walls.end(),robots[roboIndex])-walls.begin();
        //     if(i<n-1) endDist = min(endDist,robots[indexes[i+1]]-1);
        //     int endIndex = upper_bound(walls.begin(),walls.end(),endDist)-walls.begin();
        //     ans = max(ans,endIndex-roboPosIndex + solve(i+1,1));
        //     return cache[i][prevDir]=ans;
        // };
        // return solve(0,0);
    }
};


/*

45  56  58
8   7   8

50  52  58  75


*/