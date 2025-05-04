class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> specialGrid(int n) {
        int order = pow(2,n);
        ans.resize(order,vector<int>(order,0));
        solve(0,0,0,order);
        return ans;
    }

    void solve(int row,int col,int val,int order) {
        if(order==0) return;
        if(order==1) ans[row][col]=val;
        order=order/2;
        solve(row,col+order,val,order);
        solve(row+order,col+order,val+(order*order),order);
        solve(row+order,col,val+2*(order*order),order);
        solve(row,col,val+3*(order*order),order);
        return;
    }
};



/*
int tr,int br,int bl,int tl,int order

0  1  2  3  4  5  6  7  8  9  10  11  12  13  14  15   

9  6  3  0
8  7  2  1
7  4  5  2
6  5  4  3

*/