class Solution {
public:
    vector<int> ans;
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        solve(matrix,1,1,0,matrix.size()-1,0,matrix[0].size()-1); 
        return ans;
    }

    /*
    
    isHor = true
    isFor = true
    
    isHor = false
    isFor = true

    isHor = true
    isFor = false
    
    isHor = false
    isFor = false
    */

    void solve(vector<vector<int>>& matrix,int isHor,int isFor,int rowStart,int rowEnd,int colStart,int colEnd) {
        if(ans.size()==(matrix[0].size()*matrix.size())) return;
        if(isFor) {
            if(isHor) {
                int row = rowStart;
                int col = colStart;
                while(col<=colEnd) {
                    ans.push_back(matrix[row][col]);
                    col++;
                }
                solve(matrix,!isHor,isFor,rowStart+1,rowEnd,colStart,colEnd);
            } else {
                int row = rowStart;
                int col = colEnd;
                while(row<=rowEnd) {
                    ans.push_back(matrix[row][col]);
                    row++;
                }
                solve(matrix,!isHor,!isFor,rowStart,rowEnd,colStart,colEnd-1);
            }
        } else {
            if(isHor) {
                int row = rowEnd;
                int col = colEnd;
                while(col>=colStart) {
                    ans.push_back(matrix[row][col]);
                    col--;
                }
                solve(matrix,!isHor,isFor,rowStart,rowEnd-1,colStart,colEnd);
            } else {
                int row = rowEnd;
                int col = colStart;
                while(row>=rowStart) {
                    ans.push_back(matrix[row][col]);
                    row--;
                }
                solve(matrix,!isHor,!isFor,rowStart,rowEnd,colStart+1,colEnd);
            }
        }
    }
};

/*

rowStart ------ rowEnd
colStart ------ colEnd


when isHor,isFor then rowEnd--;
when isHor,!isFor then rowStart++;
when isVer,!isFor then colStart++;
when isVer,isFor then colEnd--;




*/