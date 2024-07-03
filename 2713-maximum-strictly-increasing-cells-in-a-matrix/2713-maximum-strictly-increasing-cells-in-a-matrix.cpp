class Solution {
public:
    int maxIncreasingCells(vector<vector<int>>& mat) {
        vector<vector<int>> maxIncreasingCells(mat.size(),vector<int>(mat[0].size()));
        vector<int> maxRow(mat.size());
        vector<int> maxCol(mat[0].size());
        vector<vector<int>> elementsIndex;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                elementsIndex.push_back({mat[i][j],i,j});
            }
        }
        int ans=0;
        stack<vector<int>> st;
        sort(elementsIndex.begin(),elementsIndex.end(),greater<vector<int>>());
        for(int i=0;i<elementsIndex.size();i++){
            int element=elementsIndex[i][0];
            int row=elementsIndex[i][1];
            int col=elementsIndex[i][2];
            maxIncreasingCells[row][col]=max(maxRow[row],maxCol[col])+1;
            ans=max(ans,maxIncreasingCells[row][col]);
            if(i!=elementsIndex.size()-1 && elementsIndex[i][0]==elementsIndex[i+1][0]){
                st.push({row,col,maxIncreasingCells[row][col]});
                continue;
            }
            while(!st.empty()){
                int r=st.top()[0];
                int c=st.top()[1];
                int val=st.top()[2];
                maxRow[r]=max(maxRow[r],val);
                maxCol[c]=max(maxCol[c],val);
                st.pop();
            }
            maxRow[row]=max(maxRow[row],maxIncreasingCells[row][col]);
            maxCol[col]=max(maxCol[col],maxIncreasingCells[row][col]);
        }
        return ans;
    }
};



/*

stack: 012  121  302  311    

 7   6   3
-7  -5   6
-7   0  -4
 6   6   0
-8   6   0


1   2   0
0   0   1
0   0   0
2   1   0
0   0   0


1st col= 1
2nd col= 0 
3rd col= 0
1st row= 1
2nd row= 0
3rd row= 0
4th row= 0
5th row= 0



 7   5   
-6  -2
 3   3


1   2
0   3
2   2


1st col= 1
2nd col= 2 
1st row= 2
2nd row= 0
3rd row= 2




3   1
3   4


0   0
2   1


1st row = 0
2nd row = 2
1st col = 2
2nd col = 1


1000    1111    0011
1111    0100    0000
lrtb    lrtb    lrtb

3   4   2
4   2   1

4   4   4   
4   4   4


*/