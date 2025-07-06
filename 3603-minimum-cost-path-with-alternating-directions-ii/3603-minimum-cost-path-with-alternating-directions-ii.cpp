class Solution {
public:
    using pii = pair<int, int>;
    using State = tuple<long long, int, int, int>; // cost, time, row, col

    long long minCost(int m, int n, vector<vector<int>>& waitCost) {
        priority_queue<State, vector<State>, greater<>> pq;
        pq.push({1, 1, 0, 0}); // cost, time, row, col

        vector<vector<vector<bool>>> visited(m, vector<vector<bool>>(n, vector<bool>(2, false)));
        visited[0][0][1] = true;

        vector<pii> dir = {{0, 1}, {1, 0}};

        while (!pq.empty()) {
            auto [cost, time, row, col] = pq.top(); pq.pop();

            if (row == m - 1 && col == n - 1) return cost;

            int parity = time % 2;

            if (parity == 0) {
                // Even second: wait
                if (!visited[row][col][1]) {
                    visited[row][col][1] = true;
                    pq.push({cost + waitCost[row][col], time + 1, row, col});
                }
            } else {
                // Odd second: move
                for (auto [dx, dy] : dir) {
                    int newRow = row + dx;
                    int newCol = col + dy;
                    if (newRow >= m || newCol >= n) continue;

                    if (!visited[newRow][newCol][0]) {
                        visited[newRow][newCol][0] = true;
                        long long moveCost = (newRow + 1LL) * (newCol + 1LL);
                        pq.push({cost + moveCost, time + 1, newRow, newCol});
                    }
                }
            }
        }

        return -1;
    }
};
