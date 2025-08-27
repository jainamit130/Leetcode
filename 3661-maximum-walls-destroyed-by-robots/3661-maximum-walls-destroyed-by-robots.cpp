class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        sort(walls.begin(),walls.end());
        int n = robots.size();
        vector<int> indices(n);
        iota(indices.begin(),indices.end(),0);
        sort(indices.begin(),indices.end(),[&](auto& lhs,auto& rhs) {
            return robots[lhs]<robots[rhs];
        });

        vector<vector<int>> cache(n+1,vector<int>(2,-1));
        auto solve = [&](auto&& self,int index,int prevDir) -> int {
            if(index>=n) return 0;
            if(cache[index][prevDir]!=-1) return cache[index][prevDir];
            int robotIndex = indices[index];
            // the leftmost point the bullet reaches
            // case 1: startDist reaches till robotsPos - BulletDistance
            // case 2: if a prevRobot exists startDist reaches till prevRobot pos + 1 
            // case 3: if a prevRobot exists && prevDir=1 then startDist reaches till prevRobot Bullet pos + 1
            int startDist = robots[robotIndex] - distance[robotIndex];
            if(index>0) {
                startDist = max(startDist,robots[indices[index-1]]+1);
                if(prevDir == 1) {
                    startDist = max(robots[indices[index-1]]+distance[indices[index-1]]+1,startDist);
                }
            }
            startDist = min(startDist,robots[robotIndex]);
            int startIndex = lower_bound(walls.begin(),walls.end(),startDist)-walls.begin();
            int currIndex = upper_bound(walls.begin(),walls.end(),robots[robotIndex])-walls.begin();
            int ans = 0;
            ans = max(ans,currIndex-startIndex + self(self,index+1,0));
            // the rightMost point the bullet reaches
            // case 1: endDist reaches till robotsPos + BulletDistance
            // case 2: if a nextRobot exists endDist reaches till nextRobot pos - 1 
            int endDist = robots[robotIndex]+distance[robotIndex];
            if(index<n-1) endDist = min(endDist,robots[indices[index+1]]-1);
            int endIndex = upper_bound(walls.begin(),walls.end(),endDist)-walls.begin();
            currIndex = lower_bound(walls.begin(),walls.end(),robots[robotIndex])-walls.begin();
            ans = max(ans,endIndex-currIndex+self(self,index+1,1));
            return cache[index][prevDir]=ans;
        };
        return solve(solve,0,0);
    }
};

/*

W       W    W           W       W               W               W
        R       R2                       R           R
---------        
----------------------------------------------------------------

Suppose bullet tarvel from R2 in left direction => using binary search => 
startIndex and curr pos (end Index)
smilarly the endIndex for the right direction


Dynamic Progamming 

Steps
1. Sort walls and robots array (sort index array based on robots)
2. run a dynamic programming (2 states - index, prevDir - 0,1)
3. for every index determine the startIndex and endIndex using binary search of startDist and EndDist values over walls array.
4. Handle edge cases where the robots and walls take the same position.

*/