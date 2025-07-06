class Union {
    public:
        unordered_map<int,int> parent;
        Union() {}

        int findParent(int n) {
            while(n!=parent[n]) n = findParent(parent[n]);
            return n;
        }

        void merge(int n1,int n2) {
            if(parent.find(n1)==parent.end()) parent[n1]=n1;
            if(parent.find(n2)==parent.end()) parent[n2]=n2;
            int p1 = findParent(n1); int p2 = findParent(n2);
            if(p1!=p2) parent[p1] = p2;
        }

        unordered_map<int,vector<int>> getSameValGroups() {
            unordered_map<int,vector<int>> groups;
            for(auto [row,_]:parent) {
                groups[findParent(row)].push_back(row);
            }
            return groups;
        }
};

class Solution {
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        map<int,vector<vector<int>>> valToCoord;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                valToCoord[matrix[i][j]].push_back({i,j});
            }
        }

        vector<int> rowCol(m+n,0);
        for(auto [val,coords]:valToCoord) {
            Union uf;
            for(int i=0;i<coords.size();i++) {
                int row = coords[i][0];
                int col = coords[i][1];
                uf.merge(row,col+m);
            }

            unordered_map<int,vector<int>> groups = uf.getSameValGroups();
            for(auto [row,_]:groups) {
                int maxRank = 0;
                for(auto col:groups[row]) maxRank = max(maxRank,rowCol[col]);
                for(auto col:groups[row]) rowCol[col] = maxRank + 1; 
            }

            for(int i=0;i<coords.size();i++) {
                int row = coords[i][0];
                int col = coords[i][1];
                matrix[row][col]=rowCol[row];
            }
        }
        return matrix;
    }
};