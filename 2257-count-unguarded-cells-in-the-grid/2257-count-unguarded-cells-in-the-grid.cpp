class Solution {
public:
    vector<vector<int>> grid(m, vector<int>(n, 0));
    int countUnguarded(int m, int n, vector<vector<int>>& guards,
                       vector<vector<int>>& walls) {
        grid.resize(m, vector<int>(n, 0));
        vector<int> colGuard(n);
        vector<int> revColGuard(n);
        for (auto coordinates : guards) {
            grid[coordinates[0]][coordinates[1]] = 1;
        }

        for (auto coordinates : walls) {
            grid[coordinates[0]][coordinates[1]] = 2;
        }

        for (int i = 0; i < m; i++) {
            int revI = m - i - 1;
            bool isGuarded = false;
            bool isRevGuarded = false;
            for (int j = 0; j < n; j++) {
                int revJ = n - j - 1;
                markCell();
            }
        }
            int ans = 0;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] == 0) {
                        ans++;
                    }
                }
            }
            return ans;
        }

        void markCell(int i, int j,vector<int>& colGuard, bool& isGuarded) {
            if ((isGuarded || colGuard[j]) && grid[i][j] == 0) {
                grid[i][j] = 3;
            }

            if (grid[i][j] == 1) {
                colGuard[j] = 1;
                isGuarded = true;
            } else if (grid[i][j] == 2) {
                colGuard[j] = 0;
                isGuarded = false;
            }
        }
    }
};