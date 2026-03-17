class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> nextRow(n);
        int area = 0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) nextRow[j] = matrix[i][j] ? nextRow[j]+1 : 0;
            vector<int> copyRow = nextRow;
            sort(copyRow.begin(),copyRow.end(),greater<int>());
            for(int j=0;j<n;j++) area = max(area,(j+1)*copyRow[j]);
        }
        return area;
    }
};