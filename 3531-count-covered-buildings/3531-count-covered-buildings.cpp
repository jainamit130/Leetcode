class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int,pair<int,int>> verMinMax;
        unordered_map<int,pair<int,int>> horMinMax;
        
        for(auto building:buildings) {
            if(verMinMax.find(building[0])==verMinMax.end()) verMinMax[building[0]] = {INT_MAX,INT_MIN};
            verMinMax[building[0]] = {min(building[1],verMinMax[building[0]].first),max(building[1],verMinMax[building[0]].second)};
            if(horMinMax.find(building[1])==horMinMax.end()) horMinMax[building[1]] = {INT_MAX,INT_MIN};
            horMinMax[building[1]] = {min(building[0],horMinMax[building[1]].first),max(building[0],horMinMax[building[1]].second)};
        }

        int ans = 0;
        for(auto building:buildings) {
            int minVer = verMinMax[building[0]].first;
            int maxVer = verMinMax[building[0]].second;
            if(minVer==building[1] || maxVer==building[1]) continue;
            int minHor = horMinMax[building[1]].first;
            int maxHor = horMinMax[building[1]].second;
            if(minHor==building[0] || maxHor==building[0]) continue;
            ans++;
        }
        return ans;
    }
};



/*



*/
