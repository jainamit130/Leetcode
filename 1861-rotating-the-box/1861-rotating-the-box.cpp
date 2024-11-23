class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();
        for(int i=0;i<m;i++) {
            int index = n-1;
            for(int j=n-1;j>=0;j--) {
                if(box[i][j]=='*') {
                    index = j-1;
                } else if (box[i][j]=='#' && j!=index) {
                    box[i][j]='.';
                    box[i][index]='#';
                    index-=1;
                } else if (box[i][j]=='#' && j==index) {
                    index-=1;
                }
            }
        }
        vector<vector<char>> rotatedBox(n,vector<char>(m,'.'));
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                rotatedBox[j][m-i-1]=box[i][j];
            }
        }
        return rotatedBox;
    }
};


/*


#   #   *   .
.   #   *   .


*/