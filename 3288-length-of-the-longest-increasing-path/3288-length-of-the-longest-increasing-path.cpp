class Solution {
public:
    int maxPathLength(vector<vector<int>>& coordinates, int k) {
        int n = coordinates.size();
        int startX = coordinates[k][0];
        int startY = coordinates[k][1];
        
        sort(coordinates.begin(), coordinates.end(), [](auto lhs, auto rhs) {
            if(lhs[0] == rhs[0]) {
                return lhs[1] > rhs[1]; 
            }
            return lhs[0] < rhs[0]; 
        });
        
        int ans = 0;
        vector<vector<int>> lowerHalf, upperHalf;
        
        for (int i = 0; i < n; i++) {
            if (coordinates[i][0] == startX && coordinates[i][1] == startY) continue;
            if (coordinates[i][0] < startX && coordinates[i][1] < startY) {
                lowerHalf.push_back({coordinates[i][0], coordinates[i][1]});
            } else if (coordinates[i][0] > startX && coordinates[i][1] > startY) {
                upperHalf.push_back({coordinates[i][0], coordinates[i][1]});
            }
        }
        
        ans += findLisBS(lowerHalf);
        ans += findLisBS(upperHalf);
        
        return ans + 1; 
    }

    int findLisBS(vector<vector<int>>& coordinates) {
        if (coordinates.empty()) return 0;
        
        vector<int> sortedLIS;
        sortedLIS.push_back(coordinates[0][1]);
        
        for (int i = 1; i < coordinates.size(); i++) {
            auto it = lower_bound(sortedLIS.begin(), sortedLIS.end(), coordinates[i][1]);
            if (it == sortedLIS.end()) {
                sortedLIS.push_back(coordinates[i][1]);
            } else {
                *it = coordinates[i][1]; 
            }
        }
        
        return sortedLIS.size(); 
    }
};
