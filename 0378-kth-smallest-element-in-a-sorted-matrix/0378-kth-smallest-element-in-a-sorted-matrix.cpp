class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m=matrix.size();
        int n=matrix[0].size();
        int start=matrix[0][0];
        int end=matrix[m-1][n-1];
        while(start<end){
            int mid=(start+end)/2;
            int count=findNoOfElementsLessEqualNum(matrix,n,m,mid);
            if(count>=k){
                end=mid-1;
            } else {
                start=mid+1;
            }
        }
        return start;
    }

    int findNoOfElementsLessEqualNum(vector<vector<int>>& matrix,int n,int m,int num){
        int ans=0;
        for(int i=0;i<m;i++){
            if(matrix[i][0]>num){
                break;
            }
            for(int j=0;j<n;j++){
                if(matrix[i][j]>num){
                    break;
                }
                ans++;
            }
        }
        return ans;
    }
};


/*

1(1)   2(2)   3(4)   4(6)   5(8)    6

2(3)   4(7)   6(9)   8(11)   10(13)   12
  
3(5)   6(10)   9(12)   12(14)   15(15)  18


1   2   3   4   5   6   7   8   9   10  11  12  13  14  15
1   2   2   3   3   4   4   5   6   6   8   9   10  12  15


Search Space: 1*m to m*n
This Example
start = 1 
end = 15
mid = (1+15)/2 = 8

Number of Elements <= 8 = min(8/1,6) + min(8/2,12) + 2 = 6 + 4 + 2 = 12 

if (Number of Elements less than equal to target>=k) {
    end=mid;
} else {
    start=mid+1;
}

*/