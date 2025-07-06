class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int row = 0, col = 0;
        int lastRow = n; 
        for (int jump = n - 1; jump > 0; jump -= 2) {
            int i = row, j = col;
            lastRow--;
            for (int elementCount = 0; elementCount < jump; elementCount++) {
                // row right
                int temp = matrix[j][lastRow];
                matrix[j][lastRow] = matrix[i][j];
    
                // col down
                swap(matrix[lastRow][lastRow - j + col],temp);

                // bottom left
                swap(matrix[lastRow - j + col][i],temp);

                // col up
                matrix[i][j]=temp;

                j++;
            }
            row++;
            col++;
        }
        return;
    }
};

/*

n => int +ve >0

00  01  02  03  04  05
1   2   3   4   6   5   15
5   6   7   8   8   2   25
7   8   5   9   12  3
1   7   5   6   13  24
15  7   8   7   20  1
6   2   8   4   2   35


6   15  1   7   5   1
2   7   7   8   6   2
8   8   5   5   7   3
4   9   6   9   8   4
2   20  13  12  8   6
35  1   24  3   2   5




1   2   3   4
00  01  02  03

5   6   7   8
10  11  12  13

7   8   5   9
20  21  22  23

1   7   5   6
30  31  32  33



1   7   5   1
30  20  10  00

7   8   6   2
31  21  11  01

5   5   7   3
32  22  12  02

6   9   8   4
33  23  13  03

*/