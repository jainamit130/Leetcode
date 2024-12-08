class Solution {
public:
    int maxRectangleArea(vector<vector<int>>& points) {
        set<pair<int, int>> st;
        for (auto point : points) {
            st.insert({point[0], point[1]});
        }

        int ans = INT_MIN;
        for (int i = 0; i < points.size() - 1; i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];
            for (int j = i + 1; j < points.size(); j++) {
                int x2 = points[j][0];
                int y2 = points[j][1];
                if (x1 != x2 && y1 != y2 && st.find({x1, y2}) != st.end() &&
                    st.find({x2, y1}) != st.end()) {
                    bool isValid = true;
                    for (int k = 0; k < points.size(); k++) {
                        if (k == i || k == j) {
                            continue;
                        }
                        if (points[k][0] >= min(x1, x2) &&
                            points[k][0] <= max(x1, x2) &&
                            points[k][1] >= min(y1, y2) &&
                            points[k][1] <= max(y1, y2) &&
                            !(points[k][0] == x1 && points[k][1] == y2) &&
                            !(points[k][0] == x2 && points[k][1] == y1)) {
                            isValid = false;
                            break;
                        }
                    }
                    if (isValid) {
                        ans = max(ans, abs(y2 - y1) * abs(x2 - x1));
                    }
                }
            }
        }
        if (ans == INT_MIN) {
            return -1;
        }
        return ans;
    }
};