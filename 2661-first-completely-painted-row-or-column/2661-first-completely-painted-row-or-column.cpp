class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> row(m);
        vector<int> col(n);
        unordered_map<int,pair<int,int>> valToRowColMap; 
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                valToRowColMap[mat[i][j]]={i,j};
            }
        }

        for(int i=0;i<arr.size();i++) {
            row[valToRowColMap[arr[i]].first]++;
            col[valToRowColMap[arr[i]].second]++;
            if(row[valToRowColMap[arr[i]].first]==n || col[valToRowColMap[arr[i]].second]==m) return i;
        }
        return arr.size()-1;
    }
};