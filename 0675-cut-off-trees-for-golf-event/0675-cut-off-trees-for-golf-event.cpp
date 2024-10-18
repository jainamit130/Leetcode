class Solution {
public:
    vector<int> dir = {-1, 0, 1, 0, -1};  // Simplified direction array

    int cutOffTree(vector<vector<int>>& forest) {
        vector<vector<int>> indexes;
        for(int i = 0; i < forest.size(); i++) {
            for(int j = 0; j < forest[0].size(); j++) {
                if(forest[i][j] > 1) {
                    indexes.push_back({forest[i][j], i, j});
                }
            }
        }
        sort(indexes.begin(), indexes.end());
        pair<int, int> start = {0, 0};
        int ans = 0;

        for (int i = 0; i < indexes.size(); i++) {
            pair<int, int> end = {indexes[i][1], indexes[i][2]};
            int steps = shortestPath(forest, start, end);
            if (steps == -1) {
                return -1;
            }
            ans += steps;
            start = end;
        }
        return ans;
    }

    int shortestPath(vector<vector<int>>& forest, pair<int, int>& start, pair<int, int>& end) {
        queue<pair<int, int>> q;
        q.push(start);
        int level = 0;
        vector<vector<int>> visited(forest.size(), vector<int>(forest[0].size()));
        visited[start.first][start.second] = 1;  // Mark start as visited

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto index = q.front();
                q.pop();

                if (index == end) {
                    return level;
                }

                for (int i = 0; i < 4; i++) {
                    int newRow = index.first + dir[i];
                    int newCol = index.second + dir[i + 1];
                    if (isValid(newRow, newCol, forest.size(), forest[0].size()) && 
                        forest[newRow][newCol] != 0 && visited[newRow][newCol] == 0) {
                        visited[newRow][newCol] = 1;
                        q.push({newRow, newCol});
                    }
                }
            }
            level++;
        }
        return -1;
    }

    bool isValid(int row, int col, int m, int n) {
        return row >= 0 && col >= 0 && row < m && col < n;
    }
};
