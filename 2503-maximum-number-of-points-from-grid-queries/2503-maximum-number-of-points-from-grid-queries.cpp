class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int rowCount = grid.size(), colCount = grid[0].size();
        vector<int> result(queries.size(), 0);
        // Directions for moving in 4 directions (right, down, left, up)
        vector<pair<int, int>> DIRECTIONS = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        // Iterate through each query value
        for (int queryIndex = 0; queryIndex < queries.size(); queryIndex++) {
            int queryValue = queries[queryIndex];
            queue<pair<int, int>> bfsQueue;
            // Start BFS from the top-left corner
            bfsQueue.push({0, 0});
            vector<vector<bool>> visited(rowCount,
                                         vector<bool>(colCount, false));
            // Mark the starting cell as visited
            visited[0][0] = true;
            int points = 0;

            // BFS traversal
            while (!bfsQueue.empty()) {
                int queueSize = bfsQueue.size();
                while (queueSize--) {
                    auto [currentRow, currentCol] = bfsQueue.front();
                    bfsQueue.pop();

                    // If the current cell's value is greater than or equal to
                    // queryValue, stop expanding from here
                    if (grid[currentRow][currentCol] >= queryValue) continue;

                    // Count the valid cell
                    points++;

                    // Explore all four possible directions
                    for (auto [rowOffset, colOffset] : DIRECTIONS) {
                        int newRow = currentRow + rowOffset,
                            newCol = currentCol + colOffset;

                        // Ensure the new position is within bounds and has not
                        // been visited
                        if (newRow >= 0 && newCol >= 0 && newRow < rowCount &&
                            newCol < colCount && !visited[newRow][newCol] &&
                            grid[newRow][newCol] < queryValue) {
                            bfsQueue.push({newRow, newCol});
                            // Mark the new cell as visited
                            visited[newRow][newCol] = true;
                        }
                    }
                }
            }
            // Store the result for the current query
            result[queryIndex] = points;
        }
        return result;
    }
};