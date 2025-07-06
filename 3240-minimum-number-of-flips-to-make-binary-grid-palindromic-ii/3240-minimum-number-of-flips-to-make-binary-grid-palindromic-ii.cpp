class Solution {
private:
    int countFlipsInQuadrants(const vector<vector<int>>& matrix, int rows, int cols) {
        int flips = 0;
        for (int i = 0; i < rows / 2; ++i) {
            for (int j = 0; j < cols / 2; ++j) {
                vector<int> elements = {
                    matrix[i][j],
                    matrix[rows - i - 1][j],
                    matrix[i][cols - j - 1],
                    matrix[rows - i - 1][cols - j - 1]
                };
                int onesCount = count(elements.begin(), elements.end(), 1);
                flips += min(onesCount, 4 - onesCount);
            }
        }
        return flips;
    }

    int handleMiddleRow(const vector<vector<int>>& matrix, int rows, int cols, int& possible, int& count) {
        int flips = 0;
        if (rows % 2 != 0) {
            for (int j = 0; j < cols / 2; ++j) {
                if (matrix[rows / 2][j] != matrix[rows / 2][cols - j - 1]) {
                    flips++;
                    possible++;
                } else {
                    if (matrix[rows / 2][j] == 1) {
                        count++;
                    }
                }
            }
        }
        return flips;
    }

    int handleMiddleColumn(const vector<vector<int>>& matrix, int rows, int cols, int& possible, int& count) {
        int flips = 0;
        if (cols % 2 != 0) {
            for (int i = 0; i < rows / 2; ++i) {
                if (matrix[i][cols / 2] != matrix[rows - i - 1][cols / 2]) {
                    flips++;
                    possible++;
                } else {
                    if (matrix[i][cols / 2] == 1) {
                        count++;
                    }
                }
            }
        }
        return flips;
    }

    int handleCentralElement(const vector<vector<int>>& matrix, int rows, int cols) {
        if (rows % 2 != 0 && cols % 2 != 0 && matrix[rows / 2][cols / 2] == 1) {
            return 1;
        }
        return 0;
    }

    int adjustFlips(int flips, int possible, int count) {
        if (possible == 0 && count % 2 != 0) {
            flips += 2;
        }
        return flips;
    }

public:
    int minFlips(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int totalFlips = 0;
        int possible = 0;
        int count = 0;

        totalFlips += countFlipsInQuadrants(matrix, rows, cols);
        totalFlips += handleMiddleRow(matrix, rows, cols, possible, count);
        totalFlips += handleMiddleColumn(matrix, rows, cols, possible, count);
        totalFlips += handleCentralElement(matrix, rows, cols);
        totalFlips = adjustFlips(totalFlips, possible, count);

        return totalFlips;
    }
};