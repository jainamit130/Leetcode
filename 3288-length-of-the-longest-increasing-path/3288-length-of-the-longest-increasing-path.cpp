class Solution {
public:
    int maxPathLength(vector<vector<int>>& coordinates, int k) {
        int n = coordinates.size();
        int startX = coordinates[k][0];
        int startY = coordinates[k][1];
        
        sort(coordinates.begin(), coordinates.end(), [](const vector<int>& lhs, const vector<int>& rhs) {
            if (lhs[0] == rhs[0]) return lhs[1] > rhs[1];
            return lhs[0] < rhs[0];
        });

        int ans = 0;
        vector<int> lowerLIS, upperLIS;
        
        for (int i = 0; i < n; i++) {
            if (coordinates[i][0] == startX && coordinates[i][1] == startY) continue;
            
            if (coordinates[i][0] < startX && coordinates[i][1] < startY) {
                updateLIS(lowerLIS, coordinates[i][1]);
            } else if (coordinates[i][0] > startX && coordinates[i][1] > startY) {
                updateLIS(upperLIS, coordinates[i][1]);
            }
        }

        ans += lowerLIS.size();  
        ans += upperLIS.size();  
        
        return ans + 1;  
    }

    void updateLIS(vector<int>& lis, int value) {
        auto it = lower_bound(lis.begin(), lis.end(), value);
        if (it == lis.end()) {
            lis.push_back(value);
        } else {
            *it = value;
        }
    }
};
