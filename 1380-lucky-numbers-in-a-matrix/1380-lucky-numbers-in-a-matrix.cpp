class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        unordered_set<int> st;
        vector<int> maxCols(matrix[0].size(),INT_MIN);
        for(int i=0;i<matrix.size();i++){
            int minRow=INT_MAX;
            for(int j=0;j<matrix[0].size();j++){
                minRow=min(minRow,matrix[i][j]);
                maxCols[j]=max(maxCols[j],matrix[i][j]);
            }
            st.insert(minRow);
        }
        vector<int> ans;
        for(int j=0;j<matrix[0].size();j++){
            if(st.find(maxCols[j])!=st.end()){
                ans.push_back(maxCols[j]);
                st.erase(maxCols[j]);
            }
        }
        return ans;
    }
};

/*

3   7   8       - 3
9   11  13      - 9
15  16  17      - 15

|   |   |
15  16  17

*/