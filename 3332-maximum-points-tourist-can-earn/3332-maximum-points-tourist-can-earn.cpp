class Solution {
public:
    vector<vector<int>> cache;
    int maxScore(int n, int k, vector<vector<int>>& stayScore, vector<vector<int>>& travelScore) {
        int result = 0;
        cache.resize(n+1,vector<int>(k+1,-1));
        for(int i=0;i<n;i++){
            result = max(result,solve(i,0,n,k,stayScore,travelScore));
        }
        return result;
    }

    int solve(int currCity,int currDay, int& n,int& k,vector<vector<int>>& stayScore, vector<vector<int>>& travelScore) {
        if(k==currDay){
            return 0;
        }

        if(cache[currCity][currDay]!=-1){
            return cache[currCity][currDay];
        }

        int ans=0;
        //Stay
        ans=max(ans,stayScore[currDay][currCity] + solve(currCity,currDay+1,n,k,stayScore,travelScore));
        //Travel
        for(int i=0;i<n;i++){
            ans=max(ans,travelScore[currCity][i] + solve(i,currDay+1,n,k,stayScore,travelScore));
        }
        return cache[currCity][currDay]=ans;
    }
};