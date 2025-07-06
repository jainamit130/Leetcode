class Solution {
public:
    vector<int> ans;
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        bool skip = false;
        bool moveForward = true;
        for(int i=0;i<grid.size();i++) {
            traverseRow(grid[i],moveForward,skip);
            moveForward = !moveForward;
        }
        return ans;
    }

    void traverseRow(vector<int>& row,bool moveForward,bool& skip) {
        int n = row.size();
        int i = moveForward?0:n-1;
        int inc = moveForward?1:-1;
        for(;i<n && i>=0;i+=inc) {
            if(!skip) {
                ans.push_back(row[i]);
            }
            skip=!skip;
        }
        return;
    }
};